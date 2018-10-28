INSERT INTO `mobile_phones`.`os` (`name`, `description`, `create_year`) VALUES ('iOS 12', 'Операційна система для мобільних пристроїів компанії Apple', 2018);
INSERT INTO `mobile_phones`.`os` (`name`, `description`, `create_year`) VALUES ('Android 8.1', 'Чергова версія операційної системи Android, що спростила роботу із ШІ', 2017);
INSERT INTO `mobile_phones`.`os` (`name`, `description`, `create_year`) VALUES ('Android 7.1', 'ОС отримала підтримку багатовіконності та апаратну підтримку AR', 2016);
INSERT INTO `mobile_phones`.`os` (`name`, `description`) VALUES ('iOS 11', 'ОС принесла новий дизайн, оновлений додаток  AppStore, LivePhotos та багато іншого.');

INSERT INTO `mobile_phones`.`features` (`name`, `usage`) VALUES ('NFC', 'Використовується для безконтактної оплати, а також роботи із іншими пристроями.');
INSERT INTO `mobile_phones`.`features` (`name`, `usage`) VALUES ('WiFi', 'Використовуєтсья для під\'єднання до мережі без використання кабелю');
INSERT INTO `mobile_phones`.`features` (`name`, `usage`) VALUES ('GPS', 'Найпоширеніша система визначення місцезнаходження.');
INSERT INTO `mobile_phones`.`features` (`name`, `usage`) VALUES ('GLONASS', 'Російський аналог GPS');
INSERT INTO `mobile_phones`.`features` (`name`, `usage`) VALUES ('3D Touch', 'Визанчає 3 ступені сили натискання на екран смартфону');

INSERT INTO `mobile_phones`.`creator` (`name`, `email`, `owner`, `country`) VALUES ('Apple', 'support@apple.com', 'Tim Cook', 'USA');
INSERT INTO `mobile_phones`.`creator` (`name`, `email`, `owner`, `country`) VALUES ('Samsung', 'support@samsung.com', 'Choi Gee-Sung', 'Південна Корея');
INSERT INTO `mobile_phones`.`creator` (`name`, `email`, `owner`, `country`) VALUES ('Huawei', 'support@huawei.net', 'Ren Zhengfei', 'Китай');
INSERT INTO `mobile_phones`.`creator` (`name`, `email`, `owner`, `country`) VALUES ('Xiaomi', 'support@mi.com', 'Lei Jun', 'Китай');
INSERT INTO `mobile_phones`.`creator` (`name`, `email`, `owner`, `country`) VALUES ('Honor', 'support@honor.xyz', 'Lei Jun', 'Китай');
INSERT INTO `mobile_phones`.`creator` (`name`, `email`, `owner`, `country`) VALUES ('OnePlus', 'support@op.net', 'Pete Lau', 'Китай');
INSERT INTO `mobile_phones`.`creator` (`name`, `email`, `owner`, `country`) VALUES ('OPPO', 'support@oppo.com', 'Duan Youngping', 'Китай');

INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('A12 Bionic', '2.5 GHz', '6', 'Apple');
INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('A11 Bionic', '2.4 GHz', '6', 'Apple');
INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('A10 Fusion', '2.38 GHz', '6', 'Apple');
INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('Snapdragon 845', '2.8 GHz', '8', 'Qualcomm');
INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('Exynos 9 Octa 9810', '2.9 GHz', '8', 'Samsung');
INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('Snapdragon 835', '2.45 GHz', '8', 'Qualcomm');
INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('Kirin 970', '2.36 GHz', '8', 'Honor');
INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('Snapdragon 660', '2.2 GHz', '8', 'Qualcomm');
INSERT INTO `mobile_phones`.`processor` (`name`, `frequency`, `count_of_cores`, `maker`) VALUES ('Kirin 710', '2.2 GHz', '8', 'Honor');

INSERT INTO `mobile_phones`.`shop` (`name`, `rating`, `website`) VALUES ('Rozetka', '4.5', 'https://rozetka.com.ua/');
INSERT INTO `mobile_phones`.`shop` (`name`, `rating`, `website`) VALUES ('ALLO', '4.7', 'https://allo.ua/');
INSERT INTO `mobile_phones`.`shop` (`name`, `rating`, `website`) VALUES ('Comfy', '4.6', 'https://comfy.ua/ua/');
INSERT INTO `mobile_phones`.`shop` (`name`, `rating`, `website`) VALUES ('MOYO', '3.9', 'https://www.moyo.ua');
INSERT INTO `mobile_phones`.`shop` (`name`, `rating`, `website`) VALUES ('Stylus', '3.5', 'https://stylus.ua');
INSERT INTO `mobile_phones`.`shop` (`name`, `rating`, `website`) VALUES ('Funduk.ua', '3.7', 'https://funduk.ua');
