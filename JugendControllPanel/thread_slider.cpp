#include "thread_slider.h"

thread_Slider::thread_Slider(QObject *parent)
{
    std::cout<<"started SliderThread\n";
    //setup timers
    //for Slider1
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(Slider1_Check()));
    //for Slider2
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(Slider2_Check()));
    //for Slider3
    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(Slider3_Check()));
    //for Slider4
    timer4 = new QTimer(this);
    connect(timer4, SIGNAL(timeout()), this, SLOT(Slider4_Check()));

    //setup Sliders
    SliderControl = new SliderArduino(this);
}

void thread_Slider::run()
{
    //
}

void thread_Slider::init(int val1, int val2, int val3, int val4)
{
    std::cout << "Slider init \n";

    int delay =75; //to set interval in ms for checking Sliders

    setSlider(SLIDERSETONE, val1);
    setSlider(SLIDERSETTWO, val2);
    setSlider(SLIDERSETTHREE, val3);
    setSlider(SLIDERSETFOUR, val4);

    timer1->start(delay);
    timer2->start(delay);
    timer3->start(delay);
    timer4->start(delay);
}

void thread_Slider::Slider1_Check()
{
    int SliderNew = SliderControl->get(SLIDERGETONE);
 //   std::cout<<"Slider1: read " << SliderNew << "\n";
    if (SliderNew != SliderOld[0]){
        emit Slider1_Changed(SliderNew);
        SliderOld[0] = SliderNew;
    }
}

void thread_Slider::Slider2_Check()
{
    int SliderNew = SliderControl->get(SLIDERGETTWO);
    if (SliderNew != SliderOld[1]){
        emit Slider2_Changed(SliderNew);
        SliderOld[1] = SliderNew;
    }
}

void thread_Slider::Slider3_Check()
{
    int SliderNew = SliderControl->get(SLIDERGETTHREE);
    if (SliderNew != SliderOld[2]){
        emit Slider3_Changed(SliderNew);
        SliderOld[2] = SliderNew;
    }
}

void thread_Slider::Slider4_Check()
{
    int SliderNew = SliderControl->get(SLIDERGETFOUR);
    if (SliderNew != SliderOld[3]){
        emit Slider4_Changed(SliderNew);
        SliderOld[3] = SliderNew;
    }
}

void thread_Slider::setSlider(int slider, int val)
{
    //value in % (0 - 100)
    int sliderHEX;

    switch (slider)
    {
    case 1:
        sliderHEX = SLIDERSETONE;
        break;
    case 2:
        sliderHEX = SLIDERSETTWO;
        break;
    case 3:
        sliderHEX = SLIDERSETTHREE;
        break;
    case 4:
        sliderHEX = SLIDERSETFOUR;
        break;
    }

    SliderControl->set(sliderHEX, val);
    SliderOld[slider] = val;
}

void thread_Slider::close()
{
    std::cout<<"closing SliderThread";
//    for (int i = 0; i < 4; i++)
//    {
//        setSlider(i, 0);
//    }
    timer1->stop();
    timer2->stop();
    timer3->stop();
    timer4->stop();
    this->exit();
}
