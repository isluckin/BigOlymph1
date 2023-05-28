#include <Arduino_USBHostMbed5.h>
#include <DigitalOut.h>
#include <FATFileSystem.h>
#include <ArduinoSTL.h>

USBHostMSD msd;
mbed::FATFileSystem usb("usb");

int interval = 3000000
int err;
using namespace std;
int Led = 4;
int i = 3;

void setup() {
  Serial.begin(115200);
   pinMode(PA_15, OUTPUT); 
  digitalWrite(PA_15, HIGH);

  pinMode(Led, OUTPUT);

  while (!Serial);

  msd.connect();
   err = usb.mount(&msd);

  WtiteFile();
  

}

void loop() {
}
void WriteToFile() {
  mbed::fs_file_t file;
  struct dirent *ent;
  int dirIndex = 0;
  int res = 0;
  FILE *f = fopen("/usb/filename.txt", "w+");
  while True{
    Serial.print(", Value: ");
    Serial.println(analogRead(A0));

     fflush(stdout);

      int reading = analogRead(A0);

      if (reading >= maxValue){
        digitalWrite(Led, HIGH);
      }

      delay(interval);

  }
  Serial.println("File closing");
  fflush(stdout);
  err = fclose(f);
}
