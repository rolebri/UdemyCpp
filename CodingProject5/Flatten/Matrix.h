#pragma once

#include <algorithm>
#include <array>
#include <concepts>
#include <exception>
#include <functional>
#include <iostream>
#include <type_traits>

template <std::floating_point T>
class Matrix
{
public:
    Matrix() = delete;
    Matrix(const std::size_t rows, const std::size_t cols)
        : m_rows(rows), m_cols(cols),
          m_data(std::vector<T>(rows * cols, T{})){};
    Matrix(const std::size_t rows, const std::size_t cols, const T value)
        : m_rows(rows), m_cols(cols),
          m_data(std::vector<T>(rows * cols, value)){};
    ~Matrix() noexcept = default;

    Matrix(const Matrix &other) = default;
    Matrix &operator=(const Matrix &other) = default;
    Matrix(Matrix &&other) noexcept = default;
    Matrix &operator=(Matrix &&other) noexcept = default;

    [[nodiscard]] Matrix operator+(const Matrix &rhs) const
    {
        if (m_rows != rhs.m_rows)
        {
            throw(std::invalid_argument("Number of rows are not equal!"));
        }
        if (m_cols != rhs.m_cols)
        {
            throw(std::invalid_argument("Number of cols are not equal!"));
        }

        auto result = Matrix(m_rows, m_cols);

        for (std::size_t i = 0; i < m_rows; ++i)
        {
            for (std::size_t j = 0; j < m_cols; ++j)
            {
                result.m_data[matrixIndex(m_cols, i, j)] =
                    m_data[matrixIndex(m_cols, i, j)] +
                    rhs.m_data[matrixIndex(m_cols, i, j)];
            }
        }

        return result;
    }

    [[nodiscard]] Matrix &operator+=(const Matrix &rhs)
    {
        if (m_rows != rhs.m_rows)
        {
            throw(std::invalid_argument("Number of rows are not equal!"));
        }
        if (m_cols != rhs.m_cols)
        {
            throw(std::invalid_argument("Number of cols are not equal!"));
        }

        for (std::size_t i = 0; i < m_rows; ++i)
        {
            for (std::size_t j = 0; j < m_cols; ++j)
            {
                m_data[matrixIndex(m_cols, i, j)] +=
                    rhs.m_data[matrixIndex(m_cols, i, j)];
            }
        }

        return *this;
    }

    [[nodiscard]] Matrix operator-(const Matrix &rhs) const
    {
        if (m_rows != rhs.m_rows)
        {
            throw(std::invalid_argument("Number of rows are not equal!"));
        }
        if (m_cols != rhs.m_cols)
        {
            throw(std::invalid_argument("Number of cols are not equal!"));
        }

        auto result = Matrix(m_rows, m_cols);

        for (std::size_t i = 0; i < m_rows; ++i)
        {
            for (std::size_t j = 0; j < m_cols; ++j)
            {
                result.m_data[matrixIndex(m_cols, i, j)] =
                    m_data[matrixIndex(m_cols, i, j)] -
                    rhs.m_data[matrixIndex(m_cols, i, j)];
            }
        }

        return result;
    }

    [[nodiscard]] Matrix &operator-=(const Matrix &rhs)
    {
        if (m_rows != rhs.m_rows)
        {
            throw(std::invalid_argument("Number of rows are not equal!"));
        }
        if (m_cols != rhs.m_cols)
        {
            throw(std::invalid_argument("Number of cols are not equal!"));
        }

        for (std::size_t i = 0; i < m_rows; ++i)
        {
            for (std::size_t j = 0; j < m_cols; ++j)
            {
                m_data[matrixIndex(m_cols, i, j)] -=
                    rhs.m_data[matrixIndex(m_cols, i, j)];
            }
        }

        return *this;
    }

    [[nodiscard]] Matrix operator*(const T &scalar) const
    {
        auto result = Matrix(m_rows, m_cols);

        for (std::size_t i = 0; i < m_rows; ++i)
        {
            for (std::size_t j = 0; j < m_cols; ++j)
            {
                result.m_data[matrixIndex(m_cols, i, j)] =
                    m_data[matrixIndex(m_cols, i, j)] * scalar;
            }
        }

        return result;
    }

    [[nodiscard]] Matrix &operator*=(const T &scalar)
    {
        for (std::size_t i = 0; i < m_rows; ++i)
        {
            for (std::size_t j = 0; j < m_cols; ++j)
            {
                m_data[matrixIndex(m_cols, i, j)] *= scalar;
            }
        }

        return *this;
    }

    [[nodiscard]] Matrix operator/(const T &scalar) const
    {
        if (scalar == T{})
        {
            throw(std::invalid_argument("Div by zero!"));
        }

        auto result = Matrix(m_rows, m_cols);

        for (std::size_t i = 0; i < m_rows; ++i)
        {
            for (std::size_t j = 0; j < m_cols; ++j)
            {
                result.m_data[matrixIndex(m_cols, i, j)] =
                    m_data[matrixIndex(m_cols, i, j)] / scalar;
            }
        }

        return result;
    }

    [[nodiscard]] Matrix &operator/=(const T &scalar)
    {
        if (scalar == T{})
        {
            throw(std::invalid_argument("Div by zero!"));
        }

        for (std::size_t i = 0; i < m_rows; ++i)
        {
            for (std::size_t j = 0; j < m_cols; ++j)
            {
                m_data[matrixIndex(m_cols, i, j)] /= scalar;
            }
        }

        return *this;
    }

    [[nodiscard]] Matrix operator*(const Matrix &rhs) const
    {
        if (m_cols != rhs.m_rows)
        {
            throw(std::invalid_argument("Dimensions do not match!"));
        }

        auto result = Matrix(m_rows, rhs.m_cols);

        if ((m_rows < 250 && m_cols < 250) ||
            (rhs.m_rows < 250 && rhs.m_cols < 250))
        {
            dot(*this, rhs, result);
        }
        else
        {
            parallel_dot(*this, rhs, result);
        }

        return result;
    }

    [[nodiscard]] Matrix &operator*=(const Matrix &rhs)
    {
        if (m_cols != rhs.m_rows)
        {
            throw(std::invalid_argument("Dimensiosn do not match!"));
        }

        *this = (*this) * rhs;

        return *this;
    }

    void print_matrix() const
    {
        for (std::size_t i = 0; i < m_rows; i++)
        {
            for (std::size_t j = 0; j < m_cols; j++)
            {
                std::cout << m_data[matrixIndex(m_cols, i, j)] << ", ";
            }

            std::cout << '\n';
        }
    }

    [[nodiscard]] std::size_t num_rows() const
    {
        return m_rows;
    }

    [[nodiscard]] inline std::size_t num_cols() const
    {
        return m_cols;
    }

    [[nodiscard]] static inline std::size_t matrixIndex(const std::size_t N,
                                                        const std::size_t i,
                                                        const std::size_t j)
    {
        return i * N + j;
    }


private:
    static void dot(const Matrix &matrixA,
                    const Matrix &matrixB,
                    Matrix &result)
    {
        for (std::size_t i = 0; i != matrixA.num_rows(); ++i)
        {
            for (std::size_t k = 0; k != matrixB.num_rows(); ++k)
            {
                const auto ik = matrixIndex(matrixB.num_rows(), i, k);

                for (std::size_t j = 0; j != matrixB.num_cols(); ++j)
                {
                    const auto ij = matrixIndex(matrixB.num_cols(), i, j);
                    const auto kj = matrixIndex(matrixB.num_cols(), k, j);

                    result.m_data[ij] +=
                        matrixA.m_data[ik] * matrixB.m_data[kj];
                }
            }
        }
    }

    static void parallel_dot(const Matrix &matrixA,
                             const Matrix &matrixB,
                             Matrix &result)
    {
        std::int32_t i = 0;
        std::int32_t j = 0;
        std::int32_t k = 0;

#pragma omp parallel for shared(result) private(i, j, k) num_threads(16)
        for (i = 0; i < matrixA.num_rows(); ++i)
        {
            for (k = 0; k < matrixB.num_rows(); ++k)
            {
                const auto ik = matrixIndex(matrixB.num_rows(), i, k);

                for (j = 0; j < matrixB.num_cols(); ++j)
                {
                    const auto ij = matrixIndex(matrixB.num_cols(), i, j);
                    const auto kj = matrixIndex(matrixB.num_cols(), k, j);

                    result.m_data[ij] +=
                        matrixA.m_data[ik] * matrixB.m_data[kj];
                }
            }
        }
    }

    std::size_t m_rows;
    std::size_t m_cols;
    std::vector<T> m_data;
};
