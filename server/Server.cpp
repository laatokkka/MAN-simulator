#include "Server.h"

Server::Server(int argc, char *argv[]) : app_(argc, argv) {
    main_window_ = new Menu();
    main_window_->show();

    // TODO логика симуляции
}

int Server::run() {
    return app_.exec();
}

int main(int argc, char *argv[]) {
    Server serv(argc, argv);
    return serv.run();
}