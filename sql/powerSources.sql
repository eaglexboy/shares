SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `powerSources`
--

CREATE TABLE IF NOT EXISTS `powerSources` (
  `ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `powerName` varchar(50) CHARACTER SET ascii NOT NULL,
  `powerOutput` int(11) unsigned NOT NULL,
  `shipCompatibility` int(11) unsigned NOT NULL,
  `powerPrice` float unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `powerName` (`powerName`,`powerOutput`,`shipCompatibility`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=9 ;

--
-- Dumping data for table `power_sources`
--

INSERT INTO `power_sources` VALUES(1, 'Quist Generator', 640, 1, 0);
INSERT INTO `power_sources` VALUES(2, 'Tiblanc Generator', 800, 2, 0);
INSERT INTO `power_sources` VALUES(3, 'Ana Generator', 800, 3, 0);
INSERT INTO `power_sources` VALUES(4, 'Emily Generator', 320, 4, 0);
INSERT INTO `power_sources` VALUES(5, 'Kelm Generator', 1600, 5, 0);
INSERT INTO `power_sources` VALUES(6, 'Lowell Generator', 3600, 6, 0);
INSERT INTO `power_sources` VALUES(7, 'Centred Generator', 880, 7, 0);
INSERT INTO `power_sources` VALUES(8, 'Osborne Generator', 400, 8, 0);
INSERT INTO `power_sources` VALUES(9, 'Victoria Generator', 500, 1, 0);
INSERT INTO `power_sources` VALUES(10, 'Echidna Generator', 1600, 9, 0);
INSERT INTO `power_sources` VALUES(11, 'Cartwheel Generator', 1600, 10, 0);


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
