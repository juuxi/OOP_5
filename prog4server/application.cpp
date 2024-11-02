#include "application.h"
#include "common.h"

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));

    p.change_size(2);
    p.change_an(2);
    p.change_root(1, 0);
    p.change_root(3, 1);
}

void TApplication::recieve(QByteArray msg)
{
    QString answer, s;
    TComplex x, v;
    int pos = msg.indexOf(separator);
    int t = msg.left(pos).toInt();
    switch (t)
    {
        case VALUE_REQUEST:
            msg = msg.right(msg.length()-pos-1);
            msg>>x;
            v = p.count_value(x);
            s<<(QString)x<<(QString)v;
            answer<<QString().setNum(VALUE_ANSWER);
            answer += s;
            break;
        case PRINT_CLASSIC_REQUEST:
            p.set_print_mode(EPrintModeClassic);
            s<<p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        case PRINT_CANONIC_REQUEST:
            p.set_print_mode(EPrintModeCanonic);
            s << p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        default: return;
    }
    comm->send(QByteArray().append(answer));
}
