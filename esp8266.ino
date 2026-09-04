//LAMPU OTOMATIS ALPHA TEAM 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 2          
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define RELAY_PIN 13      
const float AMBANG_SUHU = 30.0;

int xLove = 70; // Posisi awal animasi Love
int offsetGelombang = 0;
unsigned long lastApiMillis = 0; // Untuk kontrol kecepatan api

void setup() {
  Serial.begin(115200);
  Wire.begin(4, 5); 
  dht.begin();
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;); 
  }
  
  unsigned long startTime = millis();
  while(millis() - startTime < 5000) {
    display.clearDisplay();
    if ((millis() / 150) % 2 == 0) {
      display.invertDisplay((millis() / 300) % 2); 
      display.setTextSize(2); 
      display.setTextColor(1); 
      display.setCursor(5, 8);
      display.print("ALPHA TEAM");
    } else {
      display.clearDisplay();
    }
    display.display();
  }
  display.invertDisplay(false);

  pinMode(RELAY_PIN, INPUT); 
}

// Fungsi bantu untuk menggambar hati (Love) TERISI PENUH (SOLID)
void drawLove(int16_t x, int16_t y) {
  // Baris 1
  display.drawPixel(x+1, y, 1); display.drawPixel(x+3, y, 1);
  // Baris 2
  display.drawFastHLine(x, y+1, 5, 1);
  // Baris 3
  display.drawFastHLine(x, y+2, 5, 1);
  // Baris 4
  display.drawFastHLine(x+1, y+3, 3, 1);
  // Baris 5
  display.drawPixel(x+2, y+4, 1);
}

void loop() {
  float t = dht.readTemperature();
  if (isnan(t)) return;

  if (t < AMBANG_SUHU) {
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW); 
  } 
  else {
    pinMode(RELAY_PIN, INPUT); 
  }

  display.clearDisplay();
  display.setTextColor(1); 

  // HEADER: ALPHA TEAM
  if ((millis() / 200) % 2 == 0) {
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("ALPHA TEAM");
  }

  // ANIMASI LOVE BERSAUTAN (70 - 128) - SEKARANG SOLID
  for (int i = 0; i < 6; i++) {
    int posLove = xLove + (i * 10);
    if (posLove > 125) posLove -= 58; 
    drawLove(posLove, 1);
  }
  
  // Kecepatan gerak horizontal Love
  static unsigned long lastLoveMillis = 0;
  if (millis() - lastLoveMillis > 50) { 
    xLove += 1;
    lastLoveMillis = millis();
  }
  if (xLove > 115) xLove = 70; 

  // TAMPILAN SUHU (HANYA ANGKA)
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print(t, 1);

  // ANIMASI API DIBUAT SMOOTH DAN SLOW (Update tiap 200ms)
  static int seedApi = 0;
  if (millis() - lastApiMillis > 200) { // Angka 200ms untuk slow dan smooth
    seedApi = random(0, 100);
    lastApiMillis = millis();
  }
  
  randomSeed(seedApi); 
  for (int fx = 55; fx < 128; fx += 4) {
    int noiseApi = random(0, 8); 
    int startY = 22;
    display.drawLine(fx, startY, fx + 2, startY - noiseApi, 1);
    display.drawPixel(fx + 1, startY - noiseApi - 2, 1);
  }

  // WAVE ANIMATION
  for (int i = 0; i < 128; i++) {
    int yWave = 28 + 2 * sin((i + offsetGelombang) * 0.15);
    display.drawPixel(i, yWave, 1);
  }
  offsetGelombang += 3; 

  display.display();
  delay(30); 
}