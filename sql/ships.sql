SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `ships`
--

CREATE TABLE IF NOT EXISTS `ships` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `userID` bigint(10) unsigned DEFAULT NULL,
  `shipName` varchar(50) CHARACTER SET ascii NOT NULL,
  `manufacturer` int(11) unsigned NOT NULL,
  `shipClass` int(10) unsigned NOT NULL,
  `shipEmptyWeight` int(10) unsigned NOT NULL COMMENT 'Ship Empty Weight',
  `shipType` int(11) unsigned NOT NULL,
  `maxPassengers` tinyint(4) unsigned NOT NULL,
  `cargoRating` smallint(10) unsigned NOT NULL,
  `cargoHauled` smallint(10) unsigned NOT NULL,
  `crewSize` tinyint(3) unsigned NOT NULL,
  `passengers` tinyint(4) unsigned NOT NULL DEFAULT '0',
  `engineType` int(10) unsigned NOT NULL,
  `powerType` int(10) unsigned NOT NULL,
  `waterCapacity` smallint(5) unsigned NOT NULL DEFAULT '100',
  `waterAmount` float unsigned NOT NULL DEFAULT '0',
  `foodCapacity` int(10) unsigned NOT NULL DEFAULT '0',
  `foodAmount` float NOT NULL DEFAULT '100',
  `oxygenCapacity` smallint(5) unsigned NOT NULL DEFAULT '100',
  `oxygenAmount` float unsigned NOT NULL DEFAULT '0',
  `volatilesCapacity` smallint(5) unsigned NOT NULL DEFAULT '100',
  `volatilesAmount` float unsigned NOT NULL DEFAULT '0',
  `environmentalMatrixLevel` float NOT NULL DEFAULT '100',
  `shipShares` float NOT NULL,
  `shipsBankroll` float NOT NULL DEFAULT '0',
  `Owned` tinyint(1) NOT NULL DEFAULT '0',
  `ownerID` bigint(10) unsigned DEFAULT NULL,
  `shipDocked` tinyint(1) NOT NULL DEFAULT '1',
  `dockDate` datetime DEFAULT NULL,
  `currentLocation` point DEFAULT NULL,
  `departing` point DEFAULT NULL,
  `destination` point DEFAULT NULL,
  `slope` float NOT NULL DEFAULT '0' COMMENT 'slope of travel',
  `intercept` float NOT NULL DEFAULT '0' COMMENT 'value of intercept',
  `departingStation` int(10) unsigned NOT NULL DEFAULT '0',
  `destinationStation` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `userID` (`userID`,`shipName`,`shipClass`,`cargoRating`,`crewSize`,`engineType`,`powerType`,`Owned`,`ownerID`,`dockDate`),
  KEY `departingStation` (`departingStation`,`destinationStation`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
