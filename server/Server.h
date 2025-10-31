#pragma once
#include <QApplication>

#include "Menu.h"

class Server {
    private:
        QApplication app_;
        Menu* main_window_ = nullptr;
                
    public:
        explicit Server(int argc, char* argv[]);
        int run();
};