# 🔥🌡️ LAMPU PENGHANGAT OTOMATIS — ALPHA TEAM 🌡️🔥

<p align="center">

```text
     ╔══════════════════════════════════════════╗
     ║                                          ║
     ║       🔥  ALPHA TEAM  🔥                ║
     ║                                          ║
     ║       🌡️  SMART HEATING SYSTEM  🌡️      ║
     ║                                          ║
     ║          🤖  ESP8266 + DHT22             ║
     ║                                          ║
     ╚══════════════════════════════════════════╝
```

<img src="https://img.shields.io/badge/ESP8266-IoT-blue?style=for-the-badge&logo=arduino" alt="ESP8266">
<img src="https://img.shields.io/badge/DHT22-Temperature-orange?style=for-the-badge" alt="DHT22">
<img src="https://img.shields.io/badge/OLED-SSD1306-black?style=for-the-badge" alt="OLED">
<img src="https://img.shields.io/badge/Relay-Automation-red?style=for-the-badge" alt="Relay">

</p>

<p align="center">

### 🔥 Sistem Pemanas Otomatis Berbasis ESP8266 🔥

**Mendeteksi suhu → mengambil keputusan → mengendalikan relay → menampilkan informasi secara real-time.**

</p>

---

# 🌡️ APA ITU PROJECT INI?

**Lampu Penghangat Otomatis ALPHA TEAM** adalah sistem otomatis berbasis **ESP8266** yang menggunakan sensor **DHT22** untuk membaca suhu dan mengendalikan **relay** berdasarkan batas suhu yang telah ditentukan.

Sistem ini dirancang agar lampu/pemanas dapat bekerja secara otomatis tanpa perlu dikendalikan secara manual.

```text
                🌡️
             DHT22
               │
               ▼
        ┌──────────────┐
        │   ESP8266    │
        │     🧠       │
        └──────┬───────┘
               │
        ┌──────┴───────┐
        │              │
        ▼              ▼
    📺 OLED         ⚡ RELAY
                       │
                       ▼
                    🔥💡
                  PEMANAS
```

---

# ✨ HIGHLIGHTS

🔥 **Automatic Temperature Control**

🌡️ Pembacaan suhu menggunakan DHT22.

🧠 ESP8266 menjadi otak utama sistem.

⚡ Relay dikendalikan berdasarkan suhu.

📺 OLED SSD1306 menampilkan informasi suhu.

❤️ Animasi hati pada OLED.

🔥 Animasi api pada OLED.

〰️ Animasi gelombang pada OLED.

✨ Splash screen **ALPHA TEAM** saat sistem dinyalakan.

⚙️ Threshold suhu dapat diubah dengan mudah.

---

# 🎬 OLED ANIMATION

Salah satu bagian menarik dari project ini adalah tampilan OLED yang tidak hanya menampilkan angka suhu.

OLED memiliki beberapa animasi:

```text
╔════════════════════════════════╗
║ ALPHA TEAM ❤️❤️❤️❤️❤️❤️       ║
║                                ║
║ 30.5                           ║
║                                ║
║       🔥🔥🔥🔥🔥🔥🔥🔥🔥        ║
║ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ║
╚════════════════════════════════╝
```

### ❤️ LOVE ANIMATION

Animasi hati bergerak secara horizontal pada bagian atas layar.

```text
❤️    ❤️    ❤️    ❤️    ❤️
   ❤️    ❤️    ❤️    ❤️
      → → → → → → →
```

### 🔥 FIRE ANIMATION

Bagian bawah OLED menampilkan efek api yang bergerak menggunakan nilai random.

```text
       🔥   🔥    🔥
    🔥    🔥   🔥    🔥
 🔥    🔥    🔥    🔥
```

### 〰️ WAVE ANIMATION

Gelombang bergerak di bagian paling bawah layar.

```text
〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️
   〰️〰️〰️〰️〰️〰️〰️
〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️
```

---

# 🧠 HOW IT WORKS?

Sistem bekerja secara terus-menerus dalam sebuah loop.

```text
       🚀 START
          │
          ▼
   🔌 Inisialisasi
   ESP8266 + OLED + DHT22
          │
          ▼
      🌡️ Baca suhu
          │
          ▼
    Apakah suhu valid?
       /          \
     ❌            ✅
     │              │
     │              ▼
     │        🌡️ Bandingkan
     │        dengan 30°C
     │              │
     │       ┌──────┴──────┐
     │       │             │
     │     < 30°C        ≥ 30°C
     │       │             │
     │       ▼             ▼
     │   ⚡ RELAY ON    🛑 RELAY OFF
     │       │             │
     │       └──────┬──────┘
     │              │
     │              ▼
     │         📺 Update OLED
     │              │
     │              ▼
     │         🔄 Ulangi
     │
     └──────────────►
```

---

# 🌡️ LOGIKA SUHU

Sistem menggunakan:

```cpp
const float AMBANG_SUHU = 30.0;
```

Artinya batas suhu sistem adalah:

> **30°C**

Logikanya:

| Kondisi           | Relay          | Status              |
| ----------------- | -------------- | ------------------- |
| 🌡️ Suhu `< 30°C` | ⚡ Aktif        | 🔥 Pemanas bekerja  |
| 🌡️ Suhu `≥ 30°C` | 🛑 Tidak aktif | ❄️ Pemanas berhenti |

Secara sederhana:

```text
          🌡️ TEMPERATURE

             < 30°C
                │
                ▼
          ⚡ RELAY AKTIF
                │
                ▼
             🔥🔥🔥
             PEMANAS


             ≥ 30°C
                │
                ▼
          🛑 RELAY MATI
                │
                ▼
              ❄️
```

---

# 🧩 HARDWARE

| Komponen         | Fungsi                      |
| ---------------- | --------------------------- |
| 🧠 ESP8266       | Mikrokontroler utama        |
| 🌡️ DHT22        | Membaca suhu                |
| 📺 OLED SSD1306  | Menampilkan suhu & animasi  |
| ⚡ Relay          | Mengendalikan lampu/pemanas |
| 🔥 Lampu Pemanas | Sumber panas                |
| 🔌 Kabel         | Koneksi antar-komponen      |
| 🔋 Power Supply  | Sumber daya                 |

---

# 🔌 PIN CONFIGURATION

## 🌡️ DHT22

```text
DHT22
  │
  └── DATA → GPIO 2
```

| DHT22 | ESP8266 |
| ----- | ------- |
| DATA  | GPIO 2  |
| VCC   | 3.3V    |
| GND   | GND     |

---

## 📺 OLED SSD1306

OLED menggunakan komunikasi **I²C**.

Pada program:

```cpp
Wire.begin(4, 5);
```

Sehingga:

| OLED | ESP8266 |
| ---- | ------- |
| SDA  | GPIO 4  |
| SCL  | GPIO 5  |
| VCC  | 3.3V    |
| GND  | GND     |

Alamat OLED:

```text
0x3C
```

---

## ⚡ RELAY

Relay menggunakan:

```cpp
#define RELAY_PIN 13
```

| Relay  | ESP8266      |
| ------ | ------------ |
| Signal | GPIO 13      |
| VCC    | Sesuai modul |
| GND    | GND          |

---

# 📊 SYSTEM SPECIFICATION

```text
╔══════════════════════════════════════╗
║          SYSTEM SPECIFICATION        ║
╠══════════════════════════════════════╣
║ 🧠 Controller   : ESP8266            ║
║ 🌡️ Sensor       : DHT22              ║
║ 📺 Display      : OLED SSD1306       ║
║ 📐 Resolution   : 128 × 32           ║
║ ⚡ Relay        : GPIO 13             ║
║ 🌡️ Threshold    : 30.0°C             ║
║ 📡 Wi-Fi        : ESP8266 available  ║
║ 🔄 Control      : Automatic           ║
╚══════════════════════════════════════╝
```

---

# 🎨 OLED DISPLAY

OLED memiliki resolusi:

```text
128 × 32 pixels
```

Tampilan dibagi menjadi beberapa area:

```text
┌──────────────────────────────────────────────┐
│ ALPHA TEAM     ❤️ ❤️ ❤️ ❤️ ❤️ ❤️             │
│                                              │
│ 30.5                                         │
│                                              │
│                     🔥🔥🔥🔥🔥🔥🔥🔥          │
│〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️〰️│
└──────────────────────────────────────────────┘
```

### Area layar:

* 🏷️ **Header:** ALPHA TEAM
* ❤️ **Animation:** Love bergerak
* 🌡️ **Temperature:** Nilai suhu
* 🔥 **Effect:** Animasi api
* 〰️ **Bottom:** Animasi gelombang

---

# 🚀 STARTUP SCREEN

Saat ESP8266 dinyalakan, sistem menampilkan splash screen:

```text
╔════════════════════════╗
║                        ║
║     ALPHA TEAM         ║
║                        ║
╚════════════════════════╝
```

Tampilan ini berjalan selama kurang lebih **5 detik** sebelum masuk ke mode monitoring.

✨

---

# 📦 LIBRARIES

Project menggunakan beberapa library Arduino:

```cpp
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
```

### Library yang diperlukan:

* `Adafruit GFX Library`
* `Adafruit SSD1306`
* `DHT sensor library`
* `Wire`
* `SPI`

---

# 🛠️ INSTALLATION

## 1️⃣ Install Arduino IDE

Gunakan Arduino IDE untuk membuka dan meng-upload program.

## 2️⃣ Install Board ESP8266

Pastikan board ESP8266 sudah tersedia pada Arduino IDE.

## 3️⃣ Install Library

Buka:

```text
Arduino IDE
   ↓
Library Manager
   ↓
Search Library
```

Install:

```text
Adafruit GFX Library
Adafruit SSD1306
DHT sensor library
```

## 4️⃣ Buka Program

Buka:

```text
LAMPU_OTOMATIS.ino
```

## 5️⃣ Pilih Board

Pilih board ESP8266 yang sesuai dengan perangkat.

## 6️⃣ Upload

Klik:

```text
Upload 🚀
```

---

# 🔧 TUNING TEMPERATURE

Jika ingin mengubah batas suhu, cukup ubah:

```cpp
const float AMBANG_SUHU = 30.0;
```

Contoh:

```cpp
const float AMBANG_SUHU = 28.0;
```

atau:

```cpp
const float AMBANG_SUHU = 32.0;
```

Dengan begitu sistem dapat disesuaikan dengan kebutuhan project.

---

# 🧪 TESTING

Contoh kondisi sistem:

```text
🌡️ 25°C
     ↓
⚡ RELAY ON
     ↓
🔥 PEMANAS AKTIF


🌡️ 30°C
     ↓
🛑 RELAY OFF
     ↓
❄️ PEMANAS NONAKTIF
```

---

# ⚠️ TROUBLESHOOTING

### 📺 OLED tidak menyala

Periksa:

* SDA → GPIO 4
* SCL → GPIO 5
* VCC
* GND
* alamat I²C `0x3C`

---

### 🌡️ Suhu tidak terbaca

Periksa:

* Kabel DATA DHT22
* GPIO 2
* VCC
* GND
* Library DHT

---

### ⚡ Relay tidak bekerja

Periksa:

* GPIO 13
* VCC relay
* GND
* Modul relay
* Logika HIGH/LOW relay

---

### 🖥️ Serial Monitor

Gunakan:

```text
115200 baud
```

Sesuai dengan:

```cpp
Serial.begin(115200);
```

---

# 📁 PROJECT STRUCTURE

Struktur repository yang disarankan:

```text
LAMPU-OTOMATIS-ALPHA-TEAM/
│
├── 📄 README.md
│
├── 🔥 LAMPU_OTOMATIS.ino
│
├── 📷 images/
│   ├── robot.jpg
│   ├── oled.jpg
│   └── wiring.jpg
│
└── 🎬 demo/
    └── demo.mp4
```

---

# 🔮 FUTURE DEVELOPMENT

Project ini masih dapat dikembangkan menjadi sistem yang lebih kompleks.

### 🚀 Ideas

* [ ] 📡 Monitoring suhu melalui Wi-Fi
* [ ] 📱 Web dashboard
* [ ] 📊 Grafik temperatur
* [ ] ☁️ IoT cloud monitoring
* [ ] 🔔 Notifikasi ketika suhu berubah
* [ ] 📈 Data logging
* [ ] 💾 Penyimpanan histori suhu
* [ ] 🌡️ Sensor tambahan
* [ ] 🤖 Kontrol otomatis yang lebih presisi
* [ ] 📱 Mobile monitoring
* [ ] 🔋 Monitoring daya
* [ ] 🧠 Smart temperature control

---

# 🤖 THE SYSTEM IN ONE PICTURE

```text
                    🌡️
                   DHT22
                     │
                     │ Temperature
                     ▼
              ┌───────────────┐
              │               │
              │    ESP8266    │
              │      🧠       │
              │               │
              └───┬───────┬───┘
                  │       │
                  │       │
             📺   │       │   ⚡
             OLED │       │  RELAY
                  │       │
                  ▼       ▼
             ┌───────┐  ┌───────┐
             │  🌡️   │  │  🔥   │
             │DISPLAY│  │HEATER │
             └───────┘  └───────┘
```

---

# ❤️ ALPHA TEAM

```text
        █████╗ ██╗     ██████╗ ██╗  ██╗ █████╗
       ██╔══██╗██║     ██╔══██╗██║  ██║██╔══██╗
       ███████║██║     ██████╔╝███████║███████║
       ██╔══██║██║     ██╔═══╝ ██╔══██║██╔══██║
       ██║  ██║███████╗██║     ██║  ██║██║  ██║
       ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝

                  🔥 TEAM 🔥
```

### Built with:

```text
🧠 ESP8266
🌡️ DHT22
📺 OLED
⚡ Relay
🔥 Heating
💻 C/C++
❤️ Creativity
😂 Debugging
☕ Coffee
🚀 Determination
```

---

# ⭐ SUPPORT

Kalau kamu suka project ini:

⭐ **Star repository**

🍴 **Fork project**

🐛 **Report bugs**

💡 **Suggest improvements**

🤝 **Contribute**

---

<p align="center">

```text
╭────────────────────────────────────────╮
│                                        │
│       🌡️  MEASURE                      │
│               ↓                        │
│       🧠  THINK                        │
│               ↓                        │
│       ⚡  CONTROL                      │
│               ↓                        │
│       🔥  HEAT                         │
│                                        │
│          🤖 ALPHA TEAM 🤖              │
│                                        │
╰────────────────────────────────────────╯
```

### 🔥🌡️ AUTOMATE • MONITOR • INNOVATE 🌡️🔥

**Made with ❤️ by ALPHA TEAM**

</p>
