#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pawn.h"
#include "rock.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"


// Класс для шахматной доски
class Board {
private:
    std::vector<std::vector<figure::Figure*>> board;

public:
    Board() {
        board.resize(figure::BOARD_SIZE, std::vector<figure::Figure*>(figure::BOARD_SIZE, nullptr));
        initializeBoard();
    }

    ~Board() {
        // Освобождение памяти
        for (int i = 0; i < figure::BOARD_SIZE; ++i) {
            for (int j = 0; j < figure::BOARD_SIZE; ++j) {
                delete board[i][j];
            }
        }
    }

    // Инициализация начальной расстановки фигур
    void initializeBoard() {
        // Расстановка пешек
        for (int i = 0; i < figure::BOARD_SIZE; ++i) {
            board[6][i] = new figure::Pawn(figure::Color::WHITE);
            board[1][i] = new figure::Pawn(figure::Color::BLACK);
        }

        // Расстановка остальных фигур
        board[7][0] = new figure::Rook(figure::Color::WHITE);
        board[7][7] = new figure::Rook(figure::Color::WHITE);
        board[7][1] = new figure::Knight(figure::Color::WHITE);
        board[7][6] = new figure::Knight(figure::Color::WHITE);
        board[7][2] = new figure::Bishop(figure::Color::WHITE);
        board[7][5] = new figure::Bishop(figure::Color::WHITE);
        board[7][3] = new figure::Queen(figure::Color::WHITE);
        board[7][4] = new figure::King(figure::Color::WHITE);

        board[0][3] = new figure::Queen(figure::Color::BLACK);
        board[0][4] = new figure::King(figure::Color::BLACK);
        board[0][2] = new figure::Bishop(figure::Color::BLACK);
        board[0][5] = new figure::Bishop(figure::Color::BLACK);
        board[0][1] = new figure::Knight(figure::Color::BLACK);
        board[0][6] = new figure::Knight(figure::Color::BLACK);
        board[0][0] = new figure::Rook(figure::Color::BLACK);
        board[0][7] = new figure::Rook(figure::Color::BLACK);

        // Аналогично для других фигур...
    }

    // Отображение доски
    void display() const {
        std::cout << "  a b c d e f g h\n";
        for (int i = 0; i < figure::BOARD_SIZE; ++i) {
            std::cout << 8 - i << " ";
            for (int j = 0; j < figure::BOARD_SIZE; ++j) {
                if (board[i][j]) {
                    std::cout << board[i][j]->getSymbol() << " ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << 8 - i << "\n";
        }
        std::cout << "  a b c d e f g h\n";
    }

    // Проверка корректности хода
    bool isValidMove(int x1, int y1, int x2, int y2, figure::Color playerColor) const {
        if (x1 < 0 || x1 >= figure::BOARD_SIZE || y1 < 0 || y1 >= figure::BOARD_SIZE ||
            x2 < 0 || x2 >= figure::BOARD_SIZE || y2 < 0 || y2 >= figure::BOARD_SIZE) {
            return false; // Проверка границ доски
        }

        if (!board[x1][y1] || board[x1][y1]->getColor() != playerColor) {
            return false; // Проверка, что фигура принадлежит игроку
        }

        return board[x1][y1]->isValidMove(x1, y1, x2, y2, board);
    }

    // Выполнение хода
    void makeMove(int x1, int y1, int x2, int y2) {
        delete board[x2][y2]; // Удаляем фигуру на конечной клетке (если есть)
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = nullptr;
    }
};

// Класс для управления игрой
class Game {
private:
    Board board;
    figure::Color currentPlayer;

public:
    Game() : currentPlayer(figure::Color::WHITE) {}

    void start() {
        while (true) {
            board.display();
            std::cout << (currentPlayer == figure::Color::WHITE ? "White" : "Black") << "'s move: ";

            std::string move;
            std::getline(std::cin, move);

            int x1, y1, x2, y2;
            if (!parseMove(move, x1, y1, x2, y2)) {
                std::cout << "Invalid move format. Use format 'e2 e4'.\n";
                continue;
            }

            if (!board.isValidMove(x1, y1, x2, y2, currentPlayer)) {
                std::cout << "Invalid move.\n";
                continue;
            }

            board.makeMove(x1, y1, x2, y2);
            currentPlayer = (currentPlayer == figure::Color::WHITE) ? figure::Color::BLACK : figure::Color::WHITE;
        }
    }

private:
    // Преобразование шахматной нотации в координаты
    bool parseMove(const std::string& move, int& x1, int& y1, int& x2, int& y2) {
        if (move.length() != 5 || move[2] != ' ') return false;

        y1 = tolower(move[0]) - 'a';
        x1 = '8' - move[1];
        y2 = tolower(move[3]) - 'a';
        x2 = '8' - move[4];

        return x1 >= 0 && x1 < figure::BOARD_SIZE && y1 >= 0 && y1 < figure::BOARD_SIZE &&
               x2 >= 0 && x2 < figure::BOARD_SIZE && y2 >= 0 && y2 < figure::BOARD_SIZE;
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}