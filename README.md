# TÜRKÇE

# Multipurpose-Reconnaissance-Vehicle
Detaylı bilgi için ekteki `Multipurpose Reconnaissance Vehicle` raporunu inceleyiniz.

### Bölüm I: Sensörler
Bölüm I'de odak, sensörleri kodlamak ve merkezi kontrol merkezi ile iletişim kurmaktadır.

### Bölüm II: Motorlar
Bölüm II, aracın hareket yeteneklerini merkezi kontrol merkezinden kontrol etmeye odaklanmaktadır.

## Proje Açıklaması
Bu proje, gezegenin yüzeyinde çok amaçlı keşif için tasarlanmış bir Çok Amaçlı Keşif Aracını içermektedir. Araç, gezegenin çeşitli özelliklerini ve atmosfer koşullarını izlemek için çeşitli sensörler ve iletişim antenleri ile donatılmıştır. Ayrıca, çevresel koşulları değerlendirmek ve belirli görevlere yanıt vermek için bir dizi sensör içermektedir.

## Temel Özellikler
1. **İletişim Antenleri:**
   - Araç, iki iletişim anteni ile donatılmıştır.
   - Kontrol merkezi, iki iletişim anteni ile donatılmıştır.
   - Anten 1 ve Anten 2, araç ile kontrol merkezi arasında 1'e-1 iletişim kurar.
   - Anten 3 ve Anten 4, diğer uzak sensörler veya keşif ekipmanları ile iletişim kurar.

2. **Toprak Nem Sensörü (SOIL SENSOR):**
   - Gezegen yüzeyinde toprak nem seviyelerini ölçer.
   - Bitki büyüme potansiyelini analiz etmek ve yerel çevresel koşulları değerlendirmek için kullanılır.

3. **Hareket Sensörü:**
   - Araç çevresindeki hareketleri algılar.
   - Potansiyel tehlikeleri tanır ve güvenlik önlemleri alır.

4. **Sıcaklık ve Nem Sensörü (DHT11):**
   - Gezegen atmosferinde sıcaklık ve nem seviyelerini ölçer.
   - Atmosfer koşullarını değerlendirir ve aracın işletme parametrelerini optimize eder.

5. **Gaz Algılama Sensörü (MQ-3):**
   - Gezegen atmosferinde belirli gazları algılar.
   - Potansiyel tehlikeli gazları tanır ve kontrol merkezine önlemler gönderir.

6. **Su Seviye Sensörü (WATER SENSOR):**
   - Gezegen yüzeyinde yağışı ölçer.
   - Su ve yağışın varlığını değerlendirmek, sıvı suyun olası varlığını belirlemek için kullanılır.

7. **Işık Algılama Sensörü (LDR):**
   - Gezegen yüzeyinde ışık seviyelerini ölçer.
   - Gündüz ve gece koşullarını izler ve aracın enerji yönetimini optimize eder.

## Proje Hedefleri
- Gezegen yüzeyindeki çevresel koşulları izlemek ve analiz etmek.
- Potansiyel yağışları tespit etmek.
- Atmosfer verilerini toplamak ve değerlendirmek.
- Araç çevresindeki hareketleri izleyerek güvenliği sağlamak.
- İletişimi sürekli olarak kontrol merkezi ile iletişimde tutmak için iletişim antenleri kullanmak.

## Parçalar
| Parçalar                | Miktar   |
|-------------------------|----------|
| Arduino Uno Board       | 4        |
| LDR                     | 1        |
| Yağmur Sensörü          | 1        |
| DHT 11 Sensörü          | 1        |
| MQ-3                    | 1        |
| SOIL                    | 1        |
| PIR                     | 1        |
| 16x2 LCD                | 1        |
| Büyük Boy Breadboard    | 3        |
| Orta Boy Breadboard     | 1        |
| Nrf24L01(Anten)         | 4        |
| Nrf24L01(Adaptör)       | 4        |
| 330 Ohm Direnç          | 6        |
| USB KABLO               | 4        |
| LED YEŞİL               | 2        |
| Buzzer                  | 1        |
| Potansiyometre          | 1        |
| Servo Motor             | 2        |
| DC Motor                | 1        |
| Joystick                | 1        |
| Düğme                   | 1        |
| NFC                     | 1        |
| Jumper Kablo (E-E)      | 21       |
| Jumper Kablo (E-D)      | 47       |
| Jumper Kablo (D-D)      | 14       |


# ENGLISH

# Multipurpose-Reconnaissance-Vehicle
Please review the attached report titled `Multipurpose Reconnaissance Vehicle` for detailed information.

### Part I: Sensors
In Part I, the focus is on coding the sensors and establishing communication with the central control center.

### Part II: Motors
Part II focuses on controlling the movement capabilities of the vehicle from the central control center.

## Project Description
This project encompasses a Multipurpose Reconnaissance Vehicle designed for versatile exploration on the surface of the planet. The vehicle is equipped with various sensors and communication antennas to monitor diverse features and atmospheric conditions on the planet. Additionally, it includes a set of sensors to assess environmental conditions and respond to specific tasks.

## Key Features
1. **Communication Antennas:**
   - The vehicle is equipped with two communication antennas.
   - The control center is equipped with two communication antennas.
   - Antenna 1 and Antenna 2 establish 1-to-1 communication between the vehicle and the control center.
   - Antenna 3 and Antenna 4 communicate with other remote sensors or exploration equipment.

2. **Soil Moisture Sensor (SOIL SENSOR):**
   - Measures soil moisture levels on the planet surface.
   - Used for analyzing the potential for plant growth and assessing local environmental conditions.

3. **Motion Sensor:**
   - Detects movements in the vehicle's surroundings.
   - Identifies potential hazards and takes safety measures.

4. **Temperature and Humidity Sensor (DHT11):**
   - Measures temperature and humidity levels in the planet atmosphere.
   - Evaluates atmospheric conditions and optimizes the vehicle's operational parameters.

5. **Gas Detection Sensor (MQ-3):**
   - Detects specific gases in the planet atmosphere.
   - Identifies potential hazardous gases and sends precautions to the control center.

6. **Water Level Sensor (WATER SENSOR):**
   - Measures precipitation on the planet surface.
   - Used for detecting water and precipitation, assessing the potential presence of liquid water.

7. **Light Detection Sensor (LDR):**
   - Measures light levels on the planet surface.
   - Monitors day and night conditions and optimizes the vehicle's energy management.

## Project Objectives
- Monitor and analyze environmental conditions on the planet surface.
- Detect potential precipitations.
- Collect and assess atmospheric data.
- Ensure safety by monitoring movements in the vehicle's surroundings.
- Maintain continuous communication with the control center through communication antennas.

## Components
| Components               | Quantity |
|--------------------------|----------|
| Arduino Uno Board        | 4        |
| LDR                      | 1        |
| Rain Sensor              | 1        |
| DHT 11 Sensor            | 1        |
| MQ-3                     | 1        |
| SOIL                     | 1        |
| PIR                      | 1        |
| 16x2 LCD                 | 1        |
| Big Size Breadboard      | 3        |
| Middle Size Breadboard   | 1        |
| Nrf24L01(Antenna)        | 4        |
| Nrf24L01(Adapter)        | 4        |
| 330 Ohm Resistor         | 6        |
| USB CABLE                | 4        |
| LED GREEN                | 2        |
| Buzzer                   | 1        |
| Potentiometer            | 1        |
| Servo Motor              | 2        |
| DC Motor                 | 1        |
| Joystick                 | 1        |
| Button                   | 1        |
| NFC                      | 1        |
| Jumper Cables (M-M)      | 21       |
| Jumper Cables (F-M)      | 47       |
| Jumper Cables (F-F)      | 14       |
