SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `engines`
--

CREATE TABLE IF NOT EXISTS `engines` (
  `ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `engineName` varchar(50) CHARACTER SET ascii NOT NULL,
  `engineSpeed` float NOT NULL,
  `shipCompatibility` int(11) NOT NULL,
  `enginePrice` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `engineName` (`engineName`,`engineSpeed`,`shipCompatibility`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;


--
-- Dumping data for table `engines`
--

INSERT INTO `engines` VALUES(1, 'Tatiana Class Drive', 6, 1, 0);
INSERT INTO `engines` VALUES(2, 'Howard Class Drive', 7, 2, 0);
INSERT INTO `engines` VALUES(3, 'Hansen Drive', 6, 3, 0);
INSERT INTO `engines` VALUES(4, 'Jose Drive', 5, 4, 0);
INSERT INTO `engines` VALUES(5, 'Helix Drive', 2, 6, 0);
INSERT INTO `engines` VALUES(6, 'Origami Drive', 4, 6, 0);
INSERT INTO `engines` VALUES(7, 'Victor Drive', 4, 5, 0);
INSERT INTO `engines` VALUES(8, 'Lenton Drive', 4, 7, 0);
INSERT INTO `engines` VALUES(9, 'Anabel Drive', 3, 8, 0);
INSERT INTO `engines` VALUES(10, 'Rocio Drive', 4, 3, 0);
INSERT INTO `engines` VALUES(11, 'Joy Drive', 4, 1, 0);
INSERT INTO `engines` VALUES(12, 'Typhoon Drive', 5, 9, 0);
INSERT INTO `engines` VALUES(13, 'Andromeda Drive', 3, 10, 0);
INSERT INTO `engines` VALUES(14, 'Alcubierre Drive', 2, 9, 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
