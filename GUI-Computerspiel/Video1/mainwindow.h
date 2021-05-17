#pragma once

#include <string>
#include <utility>
#include <vector>

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QKeyEvent>

using Position = std::pair<unsigned int, unsigned int>;
using GameState = std::vector<std::vector<QLabel *>>;
using Obstacles = std::vector<Position>;

constexpr unsigned int NUM_OBSTACLES = 3;
constexpr unsigned int LEN_X = 5;
constexpr unsigned int LEN_Y = 5;
constexpr Position START = { 0, 0 };

enum class ConsoleInput : int
{
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
    INVALID = 4
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ConsoleInput map_user_input(char user_input);

    void update_game_state();

    void move_player(ConsoleInput move);

    void move_obstacles();

    void generate_random_obstacles();

    bool is_dead();

    bool is_finished();

    unsigned int random_uint(const unsigned int lower,
        const unsigned int upper);

    Position random_position(const unsigned int lower_x,
        const unsigned int upper_x,
        const unsigned int lower_y,
        const unsigned int upper_y);

    void start_game();

private:
    Ui::MainWindow *ui;

    Position m_player;
    Position m_goal;
    GameState m_game_state;
    Obstacles m_obstacles;
};