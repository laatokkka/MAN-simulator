#include "Menu.h"

#include <QVBoxLayout>

Menu::Menu(QWidget* parent) : QWidget(parent), blue_scored_(0), red_scored_(0) {
    setWindowTitle("Simulator");
    setAttribute(Qt::WA_DeleteOnClose);

    settings_ = new Settings(this);
    // TODO timer_ = new Timer(this);

    display_ui();
    connect_ui();

    // TODO resizeble = false;
}

void Menu::display_ui() {
    root_box_ = new QHBoxLayout();
    setLayout(root_box_);

    // Отображение примитивов
    left_panel_ = new QWidget(this);
    left_panel_->setFixedWidth(200);

    QVBoxLayout* left_box = new QVBoxLayout(left_panel_);
    settings_button_ = new QPushButton("Settings", left_panel_);

    simulation_button_ = new QPushButton("Start", left_panel_);
    simulation_button_->setCheckable(true);
    simulation_button_->setStyleSheet(
        "QPushButton {"
        "  background:#2e7d32; color:white;"
        "  border:none; border-radius:6px;"
        "  padding:3px 10px;"
        "}"
        "QPushButton:hover  { background:#388e3c; }"
        "QPushButton:pressed{ background:#1b5e20; }"
        "QPushButton:checked { background:#c62828; }"
        "QPushButton:checked:hover  { background:#e53935; }"
        "QPushButton:checked:pressed{ background:#b71c1c; }"
    );

    // Составной примитив "Табло"
    QHBoxLayout* score_box = new QHBoxLayout();
    blue_score_ = new QLabel(QString::number(blue_scored_), left_panel_);
    red_score_ = new QLabel(QString::number(red_scored_), left_panel_);

    QLabel* separator = new QLabel(":", left_panel_);

    // Настройки шрифта
    QFont score_font;
    score_font.setPointSize(48);
    score_font.setBold(true);

    separator->setAlignment(Qt::AlignCenter);
    separator->setFont(score_font);

    blue_score_->setAlignment(Qt::AlignCenter);
    blue_score_->setFont(score_font);

    red_score_->setAlignment(Qt::AlignCenter);
    red_score_->setFont(score_font);

    // Дополнительное оформление
    blue_score_->setStyleSheet("QLabel{color:#4da3ff; background:#262626; border-radius:12px; padding:6px 18px;}");
    red_score_->setStyleSheet("QLabel{color:#ff5a5f; background:#262626; border-radius:12px; padding:6px 18px;}");
    separator->setStyleSheet("QLabel{color:#bfbfbf;}");

    // Отображение зоны симуляции
    right_panel_ = new QWidget(this);
    right_panel_->setFixedWidth(370);
    right_panel_->setFixedHeight(550);

    QVBoxLayout* right_box = new QVBoxLayout(right_panel_);

    // TODO отрисовка масштабируемого поля
    game_field_ = new GameField(this);

    // Вывод всех элементов на экран

    score_box->addWidget(blue_score_);
    score_box->addWidget(separator);
    score_box->addWidget(red_score_);

    left_box->addLayout(score_box);
    left_box->addWidget(settings_button_);
    left_box->addWidget(simulation_button_);
    left_box->addStretch();

    // Тут отображение правой части
    right_box->addWidget(game_field_);
    
    root_box_->addWidget(left_panel_);
    root_box_->addWidget(right_panel_);
}

void Menu::connect_ui() {
    QObject::connect(settings_button_, &QPushButton::clicked, this, [this]{
        // TODO создание отдельного окна
    });

    QObject::connect(simulation_button_, &QPushButton::toggled, this, [this](bool is_checked) {
        // TODO добавить запуск и останова таймера симуляции

        if (is_checked) simulation_button_->setText("Stop");
        else simulation_button_->setText("Start");
    });
}