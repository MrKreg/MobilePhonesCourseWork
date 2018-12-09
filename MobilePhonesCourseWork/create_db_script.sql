-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mobile_phones
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mobile_phones
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mobile_phones` DEFAULT CHARACTER SET utf8 ;
USE `mobile_phones` ;

-- -----------------------------------------------------
-- Table `mobile_phones`.`os`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mobile_phones`.`os` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NULL,
  `description` VARCHAR(100) NULL,
  `create_year` YEAR NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mobile_phones`.`creator`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mobile_phones`.`creator` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NULL,
  `email` VARCHAR(45) NULL,
  `owner` VARCHAR(45) NULL,
  `country` VARCHAR(45) NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mobile_phones`.`processor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mobile_phones`.`processor` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NULL,
  `frequency` VARCHAR(45) NULL,
  `count_of_cores` INT NULL,
  `maker` VARCHAR(45) NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mobile_phones`.`phone`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mobile_phones`.`phone` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `creator_id` INT NOT NULL,
  `model` VARCHAR(45) NULL,
  `processor_id` INT NOT NULL,
  `storage` INT NULL,
  `RAM` INT NULL,
  `resolution` VARCHAR(45) NULL,
  `screen_size` VARCHAR(45) NULL,
  `screen_type` VARCHAR(45) NULL,
  `os_id` INT NOT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_phones_os_idx` (`os_id` ASC) VISIBLE,
  INDEX `fk_phones_creator1_idx` (`creator_id` ASC) VISIBLE,
  INDEX `fk_phone_processor1_idx` (`processor_id` ASC) VISIBLE,
  CONSTRAINT `fk_phones_os`
    FOREIGN KEY (`os_id`)
    REFERENCES `mobile_phones`.`os` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_phones_creator1`
    FOREIGN KEY (`creator_id`)
    REFERENCES `mobile_phones`.`creator` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_phone_processor1`
    FOREIGN KEY (`processor_id`)
    REFERENCES `mobile_phones`.`processor` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mobile_phones`.`shop`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mobile_phones`.`shop` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NULL,
  `rating` VARCHAR(45) NULL,
  `website` VARCHAR(45) NULL,
  `email` VARCHAR(45) NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mobile_phones`.`shop_has_phone`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mobile_phones`.`shop_has_phone` (
  `phone_id` INT NOT NULL,
  `shop_id` INT NOT NULL,
  `price` INT NOT NULL,
  `shipping_cost` INT NULL,
  `available` INT NULL,
  INDEX `fk_shop_has_phone_phone1_idx` (`phone_id` ASC) VISIBLE,
  INDEX `fk_shop_has_phone_shop1_idx` (`shop_id` ASC) VISIBLE,
  CONSTRAINT `fk_shop_has_phone_phone1`
    FOREIGN KEY (`phone_id`)
    REFERENCES `mobile_phones`.`phone` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_shop_has_phone_shop1`
    FOREIGN KEY (`shop_id`)
    REFERENCES `mobile_phones`.`shop` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mobile_phones`.`features`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mobile_phones`.`features` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(45) NULL,
  `usage` VARCHAR(45) NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mobile_phones`.`phone_has_features`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mobile_phones`.`phone_has_features` (
  `phone_id` INT NOT NULL,
  `features_id` INT NOT NULL,
  INDEX `fk_phone_has_features_phone1_idx` (`phone_id` ASC) VISIBLE,
  INDEX `fk_phone_has_features_features1_idx` (`features_id` ASC) VISIBLE,
  CONSTRAINT `fk_phone_has_features_phone1`
    FOREIGN KEY (`phone_id`)
    REFERENCES `mobile_phones`.`phone` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_phone_has_features_features1`
    FOREIGN KEY (`features_id`)
    REFERENCES `mobile_phones`.`features` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
