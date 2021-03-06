#ifndef GRADECALCULATOR_H
#define GRADECALCULATOR_H

#include <QMainWindow>

namespace Ui {
class GradeCalculator;
}

class GradeCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit GradeCalculator(QWidget *parent = 0);
    ~GradeCalculator();

signals:
    void compute_overall();

public slots:
    void update_overall(int);
    //void on_ChooseSchemePushButton_clicked();


private slots:
    void on_ChooseSchemePushButton_clicked();

private:
    Ui::GradeCalculator *ui;
};

#endif // GRADECALCULATOR_H
