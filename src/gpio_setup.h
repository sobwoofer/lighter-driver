#define ACTION 13 //D7 action input
#define LED_PIN 5 //D1 led lamp
#define PIN_MP3_TX 12 //TX D6 Player TX Connects to module's RX 
#define PIN_MP3_RX 14 //RX D5 Connects to module's TX 
#define VOLUME 0 // A0 button pin

void gpio_setup()
{
    pinMode(VOLUME, INPUT);
    pinMode(ACTION, INPUT_PULLUP);
}