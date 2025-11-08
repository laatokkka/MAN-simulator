#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QGraphicsScene>
#include <QPushButton>

#include "GameField.h"

class Menu : public QWidget {
    Q_OBJECT
    private:
        QHBoxLayout *root_box_ = nullptr;

        QWidget *left_panel_ = nullptr;
        QWidget *right_panel_ = nullptr;
        QWidget *main_window = nullptr;

        unsigned short blue_scored_, red_scored_;

        QLabel *blue_score_ = nullptr;
        QLabel *red_score_ = nullptr;
        QLabel *clock_ = nullptr;

        QPushButton *settings_button_ = nullptr;
        QPushButton *simulation_button_ = nullptr;

        GameField *game_field_ = nullptr;

        // TODO Settings напрямую в классе Menu

        // TODO cигналы связать с отправкой сигналов ИА
        // Timer* timer_ = nullptr;

        void display_ui();
        void connect_ui();

    public:
        explicit Menu(QWidget *parent = nullptr);
};