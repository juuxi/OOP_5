#include "interface.h"
#include "common.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Работа №5");
    setFixedSize(1000,500);

    a_name = new QLabel("a = ", this);
    a_name->setGeometry(100, 30, 20, 20);
    a_re = new QLineEdit(this);
    a_re->setGeometry(120, 30, 30, 20);
    a_delimiter = new QLabel("+ i ", this);
    a_delimiter->setGeometry(150, 30, 20, 20);
    a_im = new QLineEdit(this);
    a_im->setGeometry(170, 30, 30, 20);
    a_name->hide();
    a_re->hide();
    a_delimiter->hide();
    a_im->hide();

    write_mode = new QLabel("Введите an", this);
    write_mode->setGeometry(100, 10, 150, 20);
    write_mode->hide();

    an_name = new QLabel("a = ", this);
    an_name->setGeometry(100, 30, 20, 20);
    an_re = new QLineEdit(this);
    an_re->setGeometry(120, 30, 30, 20);
    an_delimiter = new QLabel("+ i ", this);
    an_delimiter->setGeometry(150, 30, 20, 20);
    an_im = new QLineEdit(this);
    an_im->setGeometry(170, 30, 30, 20);
    an_name->hide();
    an_re->hide();
    an_delimiter->hide();
    an_im->hide();

    pos_root_name = new QLabel("индекс", this);
    pos_root_name->setGeometry(100, 70, 60, 20);
    pos_root_val = new QLineEdit(this);
    pos_root_val->setGeometry(160, 70, 20, 20);
    pos_root_name->hide();
    pos_root_val->hide();

    x_name = new QLabel("x = ", this);
    x_name->setGeometry(100, 30, 20, 20);
    x_re = new QLineEdit(this);
    x_re->setGeometry(120, 30, 30, 20);
    x_delimiter = new QLabel("+ i ", this);
    x_delimiter->setGeometry(150, 30, 20, 20);
    x_im = new QLineEdit(this);
    x_im->setGeometry(170, 30, 30, 20);
    x_name->hide();
    x_re->hide();
    x_delimiter->hide();
    x_im->hide();

    new_size_name = new QLabel("Новый размер - ", this);
    new_size_name->setGeometry(100, 30, 120, 20);
    new_size_value = new QLineEdit(this);
    new_size_value->setGeometry(220, 30, 30, 20);
    new_size_name->hide();
    new_size_value->hide();

    value_btn = new QPushButton("Вычислить значение в x", this);
    value_btn->setGeometry(50, 250, 200, 30);
    change_an_btn = new QPushButton("Изменить an", this);
    change_an_btn->setGeometry(260, 250, 150, 30);
    print_btn = new QPushButton("Вывести полином", this);
    print_btn->setGeometry(420, 250, 150, 30);
    write_btn = new QPushButton("Ввести полином", this);
    write_btn->setGeometry(580, 250, 150, 30);
    change_size_btn = new QPushButton("Изменить размер", this);
    change_size_btn->setGeometry(740, 250, 150, 30);
    change_root_btn = new QPushButton("Изменить корень", this);
    change_root_btn->setGeometry(260, 210, 150, 30);

    submit_value_btn = new QPushButton("Применить", this);
    submit_value_btn->setGeometry(200, 150, 150, 30);
    submit_value_btn->hide();
    submit_an_btn = new QPushButton("Применить", this);
    submit_an_btn->setGeometry(200, 150, 150, 30);
    submit_an_btn->hide();
    submit_print_btn = new QPushButton("Применить", this);
    submit_print_btn->setGeometry(200, 150, 150, 30);
    submit_print_btn->hide();
    submit_write_btn = new QPushButton("Далее", this);
    submit_write_btn->setGeometry(200, 150, 150, 30);
    submit_write_btn->hide();
    submit_change_size_btn = new QPushButton("Применить", this);
    submit_change_size_btn->setGeometry(200, 150, 150, 30);
    submit_change_size_btn->hide();
    submit_change_root_btn = new QPushButton("Применить", this);
    submit_change_root_btn->setGeometry(200, 150, 150, 30);
    submit_change_root_btn->hide();

    print_mode = new QComboBox(this);
    print_mode->addItem("Классический");
    print_mode->addItem("Канонический");
    print_mode->setGeometry(100, 30, 130, 20);
    print_mode->hide();

    output = new QLabel(this);
    output->setGeometry(150, 350, 500, 50);

    output = new QLabel(this);
    output->setGeometry(10,200,280,25);

    connect(value_btn, SIGNAL(pressed()), this, SLOT(value()));
    connect(change_an_btn, SIGNAL(pressed()), this, SLOT(change_an()));
    connect(print_btn, SIGNAL(pressed()), this, SLOT(print()));
    connect(write_btn, SIGNAL(pressed()), this, SLOT(write()));
    connect(change_size_btn, SIGNAL(pressed()), this, SLOT(change_size()));
    connect(change_root_btn, SIGNAL(pressed()), this, SLOT(change_root()));
    connect(submit_an_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_value_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_print_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_write_btn, SIGNAL(pressed()), this, SLOT(write()));
    connect(submit_change_size_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(submit_change_root_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete value_btn;
    delete change_an_btn;
    delete print_btn;
    delete write_btn;
    delete change_size_btn;
    delete change_root_btn;

    delete submit_an_btn;
    delete submit_value_btn;
    delete submit_print_btn;
    delete submit_write_btn;
    delete submit_change_size_btn;
    delete submit_change_root_btn;

    delete print_mode;

    delete a_name;
    delete a_delimiter;
    delete a_re;
    delete a_im;

    delete write_mode;

    delete x_name;
    delete x_delimiter;
    delete x_re;
    delete x_im;

    delete an_name;
    delete an_delimiter;
    delete an_re;
    delete an_im;

    delete new_size_name;
    delete new_size_value;

    delete output;
}

void TInterface::value()
{
    output->setText("");
    x_name->show();
    x_re->show();
    x_delimiter->show();
    x_im->show();
    submit_value_btn->show();
}

void TInterface::formRequest()
{
    QString msg;
    //msg << b_re->text() << b_im->text();
    //msg << c_re->text() << c_im->text();
    QPushButton *btn = (QPushButton*)sender();
    if (btn == submit_value_btn)
    {
        msg << QString().setNum(VALUE_REQUEST);
        msg << x_re->text() << x_im->text();
    }
    /*if (btn == print_classic_btn)
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    if (btn == print_canonic_btn)
        msg << QString().setNum(PRINT_CANONIC_REQUEST);*/
    emit request(msg);
}

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case VALUE_ANSWER:
            text = "p";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += " = ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            break;
        case PRINT_ANSWER:
            text = "p(x) = ";
            text += msg;
            output->setText(text);
            break;
        default: break;
    }
}
