CREATE DATABASE mobile_phones
COLLATE SQL_Ukrainian_CP1251_CI_AS;

USE mobile_phones;

CREATE TABLE creator (
  id INT NOT NULL IDENTITY PRIMARY KEY,
  name VARCHAR(45) NULL DEFAULT NULL,
  email VARCHAR(45) NULL DEFAULT NULL,
  owner VARCHAR(45) NULL DEFAULT NULL,
  country VARCHAR(45) NULL DEFAULT NULL,
  );

CREATE TABLE features (
  id INT NOT NULL IDENTITY PRIMARY KEY,
  name VARCHAR(45) NULL DEFAULT NULL,
  usage VARCHAR(100) NULL DEFAULT NULL);

CREATE TABLE os (
  id INT NOT NULL IDENTITY PRIMARY KEY,
  name VARCHAR(45) NULL DEFAULT NULL,
  description VARCHAR(100) NULL DEFAULT NULL,
  create_year INT NULL DEFAULT NULL);

CREATE TABLE processor (
  id INT NOT NULL IDENTITY PRIMARY KEY,
  name VARCHAR(45) NULL DEFAULT NULL,
  frequency VARCHAR(45) NULL DEFAULT NULL,
  count_of_cores INT NULL DEFAULT NULL,
  maker VARCHAR(45) NULL DEFAULT NULL);

CREATE TABLE phone (
  id INT NOT NULL IDENTITY PRIMARY KEY,
  creator_id INT NOT NULL,
  model VARCHAR(45) NULL DEFAULT NULL,
  processor_id INT NOT NULL,
  storage INT NULL DEFAULT NULL,
  RAM INT NULL DEFAULT NULL,
  resolution VARCHAR(45) NULL DEFAULT NULL,
  screen_size VARCHAR(45) NULL DEFAULT NULL,
  screen_type VARCHAR(45) NULL DEFAULT NULL,
  os_id INT NOT NULL,
  CONSTRAINT fk_phone_processor1
    FOREIGN KEY (processor_id)
    REFERENCES processor (id)
	ON DELETE CASCADE
	ON UPDATE CASCADE,
  CONSTRAINT fk_phones_creator1
    FOREIGN KEY (creator_id)
    REFERENCES creator (id),
  CONSTRAINT fk_phones_os
    FOREIGN KEY (os_id)
    REFERENCES os (id)
	ON DELETE CASCADE
	ON UPDATE CASCADE);

CREATE TABLE phone_has_features (
  id INT NOT NULL IDENTITY PRIMARY KEY,
  phone_id INT NOT NULL,
  features_id INT NOT NULL,
  CONSTRAINT fk_phone_has_features_features1
    FOREIGN KEY (features_id)
    REFERENCES features (id)
	ON DELETE CASCADE
	ON UPDATE CASCADE,
  CONSTRAINT fk_phone_has_features_phone1
    FOREIGN KEY (phone_id)
    REFERENCES phone (id)
	ON DELETE CASCADE
	ON UPDATE CASCADE);

CREATE TABLE shop (
  id INT NOT NULL IDENTITY PRIMARY KEY,
  name VARCHAR(45) NULL DEFAULT NULL,
  rating DECIMAL(4,1) NULL DEFAULT NULL,
  website VARCHAR(45) NULL DEFAULT NULL);

CREATE TABLE shop_has_phone (
  id INT NOT NULL IDENTITY PRIMARY KEY,
  phone_id INT NOT NULL,
  shop_id INT NOT NULL,
  price INT NOT NULL,
  shipping_cost INT NULL DEFAULT NULL,
  available INT NULL DEFAULT NULL,
  CONSTRAINT fk_shop_has_phone_phone1
    FOREIGN KEY (phone_id)
    REFERENCES phone (id)
	ON DELETE CASCADE
	ON UPDATE CASCADE,
  CONSTRAINT fk_shop_has_phone_shop1
    FOREIGN KEY (shop_id)
    REFERENCES shop (id)
	ON DELETE CASCADE
	ON UPDATE CASCADE);

SET IDENTITY_INSERT creator ON;
INSERT INTO creator (id, name, email, owner, country) VALUES (1,'Apple','support@apple.com','Tim Cook','USA'),(2,'Samsung','support@samsung.com','Choi Gee-Sung','Південна Корея'),(3,'Huawei','support@huawei.net','Ren Zhengfei','Китай'),(4,'Xiaomi','support@mi.com','Lei Jun','Китай'),(5,'Honor','support@honor.xyz','Lei Jun','Китай'),(6,'OnePlus','support@op.net','Pete Lau','Китай'),(7,'OPPO','support@oppo.com','Duan Youngping','Китай');
SET IDENTITY_INSERT creator OFF;
SET IDENTITY_INSERT features ON;
INSERT INTO features (id, name, usage) VALUES (1,'NFC','Використовується для безконтактної оплати, а також роботи із іншими пристроями.'),(2,'WiFi','Використовуєтсья для підєднання до мережі без використання кабелю'),(3,'GPS','Найпоширеніша система визначення місцезнаходження.'),(4,'GLONASS','Російський аналог GPS'),(5,'3D Touch','Визначає 3 ступені сили натискання на екран смартфону'),(6,'Quick Charge','Технологія швидкої зарядки акамулятора телефона.');
SET IDENTITY_INSERT features OFF;
SET IDENTITY_INSERT os ON;
INSERT INTO os (id, name, description, create_year) VALUES (1,'iOS 12','Операційна система для мобільних пристроїів компанії Apple',2018),(2,'Android 8.1','Чергова версія операційної системи Android, що спростила роботу із ШІ',2017),(3,'Android 7.1','ОС отримала підтримку багатовіконності та апаратну підтримку AR',2016),(4,'iOS 11','ОС принесла новий дизайн, оновлений додаток  AppStore, LivePhotos та багато іншого.',2017),(5,'iOS 10','Доступна API Siri для сторонніх розробників і зміна дизайну програм',2016);
SET IDENTITY_INSERT os OFF;
SET IDENTITY_INSERT processor ON;
INSERT INTO processor (id, name, frequency, count_of_cores, maker) VALUES (1,'A12 Bionic','2.5 GHz',6,'Apple'),(2,'A11 Bionic','2.4 GHz',6,'Apple'),(3,'A10 Fusion','2.38 GHz',6,'Apple'),(4,'Snapdragon 845','2.8 GHz',8,'Qualcomm'),(5,'Exynos 9 Octa 9810','2.9 GHz',8,'Samsung'),(6,'Snapdragon 835','2.45 GHz',8,'Qualcomm'),(7,'Kirin 970','2.36 GHz',8,'Honor'),(8,'Snapdragon 660','2.2 GHz',8,'Qualcomm'),(9,'Kirin 710','2.2 GHz',8,'Honor');
SET IDENTITY_INSERT processor OFF;
SET IDENTITY_INSERT phone ON;
INSERT INTO phone (id, creator_id, model, processor_id, storage, RAM, resolution, screen_size, screen_type, os_id) VALUES (1,1,'iPhone 7',3,128,2,'1334x750','4.7"','Retina',5),(2,1,'iPhone 7 Plus',3,128,3,'1920x1080','5.5"','Retina',5),(3,2,'Galaxy S9',5,64,4,'2960x1440','5.8"','Super Amoled',2),(4,4,'Mi 8',4,64,6,'2248×1080','6.21"','Super Amoled',2),(5,4,'Mi A2',8,64,4,'2160x1080','5.99\','IPS',2),(6,3,'P Smart Plus',9,64,4,'2340x1080','6.3"','IPS',2),(7,5,'8X',9,64,4,'2340x1080','6.5"','LTPS',2),(8,5,'Play',7,64,4,'2340x1080','6.3"','IPS',2),(9,3,'P20 Pro',7,128,6,'2240x1080','6.1"','OLED',3),(10,1,'iPhone X',2,64,3,'2436x1125','5.8"','Super Retina (OLED)',4),(11,1,'iPhone XR',1,128,4,'1792x828','6.1"','Retina',1),(12,6,'6',4,64,6,'2280x1080','6.28"','Amoled',2),(13,7,'Find X',4,256,8,'2340x1080','6.42"','Amoled',2),(14,2,'Galaxy S8',6,64,4,'2960x1440','5.8"','Super Amoled',3),(15,2,'Galaxy Note 9',5,128,6,'2960x1440','6.4"','Super Amoled',2);
SET IDENTITY_INSERT phone OFF;
SET IDENTITY_INSERT phone_has_features ON;
INSERT INTO phone_has_features (phone_id, features_id, id) VALUES (1,1,1),(1,2,2),(1,3,3),(1,4,4),(1,5,5),(2,1,6),(2,2,7),(2,3,8),(2,4,9),(2,5,10),(3,1,11),(3,2,12),(3,3,13),(3,4,14),(3,6,15),(4,1,16),(4,2,17),(4,3,18),(4,4,19),(5,2,20),(5,3,21),(5,4,22),(6,2,23),(6,3,24),(6,4,25),(7,1,26),(7,2,27),(7,3,28),(7,4,29),(8,1,30),(8,2,31),(8,3,32),(8,4,33),(9,1,34),(9,2,35),(9,3,36),(9,4,37),(9,6,38),(10,1,39),(10,2,40),(10,3,41),(10,4,42),(10,5,43),(10,6,44),(11,1,45),(11,2,46),(11,3,47),(11,4,48),(11,6,49),(12,1,50),(12,2,51),(12,3,52),(12,4,53),(12,6,54),(13,1,55),(13,2,56),(13,3,57),(13,4,58),(13,6,59),(14,1,60),(14,2,61),(14,3,62),(14,4,63),(15,1,64),(15,2,65),(15,3,66),(15,4,67),(15,6,68);
SET IDENTITY_INSERT phone_has_features OFF;
SET IDENTITY_INSERT shop ON;
INSERT INTO shop (id, name, rating, website) VALUES (1,'Rozetka',4.5,'https://rozetka.com.ua/'),(2,'ALLO',4.7,'https://allo.ua/'),(3,'Comfy',4.6,'https://comfy.ua/ua/'),(4,'MOYO',3.9,'https://www.moyo.ua'),(5,'Stylus',3.5,'https://stylus.ua'),(6,'Funduk.ua',3.7,'https://funduk.ua');
SET IDENTITY_INSERT shop OFF;
SET IDENTITY_INSERT shop_has_phone ON;
INSERT INTO shop_has_phone (id, phone_id, shop_id, price, shipping_cost, available) VALUES (1,1,4,20999,0,1),(2,1,2,19999,0,1),(3,1,5,17599,50,1),(4,1,1,17809,50,1),(5,1,6,20989,40,1),(6,1,3,19999,0,0),(7,2,1,22250,50,1),(8,2,2,23999,50,1),(9,2,3,23499,0,0),(10,2,4,25999,0,1),(11,2,5,21499,50,1),(12,2,6,23999,40,0),(13,3,1,22999,50,1),(14,3,2,22999,0,1),(15,3,3,25999,0,1),(16,3,4,22999,0,1),(17,3,5,16999,50,1),(18,3,6,23999,50,1),(19,4,1,13999,50,1),(20,4,2,13999,0,1),(21,4,5,11399,50,1),(22,4,6,11799,50,1),(23,5,1,6999,50,1),(24,5,2,6999,0,1),(25,5,3,6999,0,1),(26,5,6,6999,50,1),(27,6,1,7799,50,1),(28,6,2,7799,0,1),(29,6,3,7799,0,1),(30,6,4,7799,0,1),(31,6,5,7499,50,1),(32,6,6,7395,50,1),(33,7,2,7699,0,1),(34,7,3,7699,0,1),(35,8,2,9999,0,1),(36,8,3,9999,0,1),(37,8,4,10599,50,1),(38,9,1,24799,50,1),(39,9,2,24799,0,1),(40,9,3,24799,0,1),(41,9,4,24799,0,1),(42,9,5,20499,50,1),(43,9,6,22499,50,1),(44,10,2,31999,0,1),(45,10,3,31999,0,1),(46,10,4,31999,0,1),(47,10,5,26999,50,1),(48,10,6,35999,50,1),(49,11,2,33999,0,0),(50,11,3,33999,0,0),(51,11,4,33999,0,0),(52,11,5,29499,50,1),(53,12,2,13999,0,1),(54,12,5,12999,50,1),(55,14,1,18499,50,1),(56,14,2,18499,0,1),(57,14,3,18499,0,1),(58,14,4,18499,0,1),(59,14,5,13499,50,1),(60,14,6,19999,50,1),(61,15,1,32999,50,1),(62,15,2,32999,0,1),(63,15,3,34999,0,1),(64,15,5,23999,50,1),(65,15,6,34999,50,1);
SET IDENTITY_INSERT shop_has_phone OFF;