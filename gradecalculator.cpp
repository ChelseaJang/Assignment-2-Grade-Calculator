#include "gradecalculator.h"
#include "ui_gradecalculator.h"
#include <QVector>

GradeCalculator::GradeCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeCalculator)
{
    ui->setupUi(this);

    // connect horizontal sliders to spinboxes
    connect(ui->HW1_HorzSlider,SIGNAL(valueChanged(int)),
            ui->HW1_spinBox,SLOT(setValue(int)));
    connect(ui->HW2_HorzSlider,SIGNAL(valueChanged(int)),
            ui->HW2_spinBox,SLOT(setValue(int)));
    connect(ui->HW3_HorzSlider,SIGNAL(valueChanged(int)),
            ui->HW3_spinBox,SLOT(setValue(int)));
    connect(ui->HW4_HorzSlider,SIGNAL(valueChanged(int)),
            ui->HW4_spinBox,SLOT(setValue(int)));
    connect(ui->HW5_HorzSlider,SIGNAL(valueChanged(int)),
            ui->HW5_spinBox,SLOT(setValue(int)));
    connect(ui->HW6_HorzSlider,SIGNAL(valueChanged(int)),
            ui->HW6_spinBox,SLOT(setValue(int)));
    connect(ui->HW7_HorzSlider,SIGNAL(valueChanged(int)),
            ui->HW7_spinBox,SLOT(setValue(int)));
    connect(ui->HW8_HorzSlider,SIGNAL(valueChanged(int)),
            ui->HW8_spinBox,SLOT(setValue(int)));
    connect(ui->Midterm1_HorzSlider,SIGNAL(valueChanged(int)),
            ui->Midterm1_spinBox,SLOT(setValue(int)));
    connect(ui->Midterm2_HorzSlider,SIGNAL(valueChanged(int)),
            ui->Midterm2_spinBox,SLOT(setValue(int)));
    connect(ui->Final_HorzSlider,SIGNAL(valueChanged(int)),
            ui->Final_spinBox,SLOT(setValue(int)));

    // update score values when slider values change
    connect(ui->HW1_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW2_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW3_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW4_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW5_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW6_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW7_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW8_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->Midterm1_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->Midterm2_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->Final_HorzSlider,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));

    // connect spinboxes to horizontal sliders
    connect(ui->HW1_spinBox,SIGNAL(valueChanged(int)),
            ui->HW1_HorzSlider,SLOT(setValue(int)));
    connect(ui->HW2_spinBox,SIGNAL(valueChanged(int)),
            ui->HW2_HorzSlider,SLOT(setValue(int)));
    connect(ui->HW3_spinBox,SIGNAL(valueChanged(int)),
            ui->HW3_HorzSlider,SLOT(setValue(int)));
    connect(ui->HW4_spinBox,SIGNAL(valueChanged(int)),
            ui->HW4_HorzSlider,SLOT(setValue(int)));
    connect(ui->HW5_spinBox,SIGNAL(valueChanged(int)),
            ui->HW5_HorzSlider,SLOT(setValue(int)));
    connect(ui->HW6_spinBox,SIGNAL(valueChanged(int)),
            ui->HW6_HorzSlider,SLOT(setValue(int)));
    connect(ui->HW7_spinBox,SIGNAL(valueChanged(int)),
            ui->HW7_HorzSlider,SLOT(setValue(int)));
    connect(ui->HW8_spinBox,SIGNAL(valueChanged(int)),
            ui->HW8_HorzSlider,SLOT(setValue(int)));
    connect(ui->Midterm1_spinBox,SIGNAL(valueChanged(int)),
            ui->Midterm1_HorzSlider,SLOT(setValue(int)));
    connect(ui->Midterm2_spinBox,SIGNAL(valueChanged(int)),
            ui->Midterm2_HorzSlider,SLOT(setValue(int)));
    connect(ui->Final_spinBox,SIGNAL(valueChanged(int)),
            ui->Final_HorzSlider,SLOT(setValue(int)));

    // update score values when spinbox values change
    connect(ui->HW1_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW2_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW3_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW4_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW5_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW6_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW7_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->HW8_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->Midterm1_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->Midterm2_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));
    connect(ui->Final_spinBox,SIGNAL(valueChanged(int)),
            this,SLOT(update_overall(int)));

    // not really working, I'm not quite sure why
    //connect(ui->ChooseSchemePushButton,SIGNAL(clicked()),
     //       this,SLOT(update_overall(int)));

    connect(ui->SchemeA_radioButton,SIGNAL(toggled(bool)),
            this,SLOT(update_overall(int)));

}

GradeCalculator::~GradeCalculator()
{
    delete ui;
}



void GradeCalculator::update_overall(int){

    int minScore = 0; // find minimum homework score
    int hw_total = 0; // calculate total HW score (with 7 highest of 8 grades)

    hw_total += ui->HW1_spinBox->value();
    minScore=ui->HW1_spinBox->value();
    hw_total += ui->HW2_spinBox->value();
    if(minScore>ui->HW2_spinBox->value()){
        minScore=ui->HW2_spinBox->value();
    }
    hw_total += ui->HW3_spinBox->value();
    if(minScore>ui->HW3_spinBox->value()){
        minScore=ui->HW3_spinBox->value();
    }
    hw_total += ui->HW4_spinBox->value();
    if(minScore>ui->HW4_spinBox->value()){
        minScore=ui->HW4_spinBox->value();
    }
    hw_total += ui->HW5_spinBox->value();
    if(minScore>ui->HW5_spinBox->value()){
        minScore=ui->HW5_spinBox->value();
    }
    hw_total += ui->HW6_spinBox->value();
    if(minScore>ui->HW6_spinBox->value()){
        minScore=ui->HW6_spinBox->value();
    }
    hw_total += ui->HW7_spinBox->value();
    if(minScore>ui->HW7_spinBox->value()){
        minScore=ui->HW7_spinBox->value();
    }
    hw_total += ui->HW8_spinBox->value();
    if(minScore>ui->HW8_spinBox->value()){
        minScore=ui->HW8_spinBox->value();
    }
    hw_total -= minScore;


    // score with scheme A
    double scoreA = 0.25/7*hw_total
            +0.2*(ui->Midterm1_spinBox->value()+ui->Midterm2_spinBox->value())
            +0.35*(ui->Final_spinBox->value());

    // score with scheme B
    // use a ternary operator to get higher midterm score
    double scoreB = 0.25/7*hw_total
            +0.3*(((ui->Midterm1_spinBox->value())>(ui->Midterm2_spinBox->value()))?
                      (ui->Midterm1_spinBox->value()):(ui->Midterm2_spinBox->value()))
            +0.45*(ui->Final_spinBox->value());

    // calculate and determine midterm scores with different schemes
    // if grading with scheme A
    if(ui->SchemeA_radioButton->isChecked()){
        // display scoreA
        ui->Score_label->setNum(scoreA);
    }
    // if grading with scheme B
    else if (ui->SchemeB_radioButton->isChecked()){
        //display scoreB
        ui->Score_label->setNum(scoreB);
    }
    // set score to 0.0 if no scheme is chosen
    else{
        ui->Score_label->setNum(0.0);
    }

    ((scoreA>scoreB)?ui->SchemeRec->setText("Scheme A"):ui->SchemeRec->setText("Scheme B"));

    int classGrade = ((scoreA>scoreB)?scoreA:scoreB);
    if(classGrade>=90){
        ui->ClassGrade->setText("A");
    }
    else if(classGrade>=80){
        ui->ClassGrade->setText("B");
    }
    else if(classGrade>=70){
        ui->ClassGrade->setText("C");
    }
    else if(classGrade>=60){
        ui->ClassGrade->setText("D");
    }
    else{
        ui->ClassGrade->setText("F");
    }

    return;
}


void GradeCalculator::on_ChooseSchemePushButton_clicked()
{
    SLOT(update_overall());
}
