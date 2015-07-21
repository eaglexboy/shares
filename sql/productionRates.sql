SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `productionRates`
--

CREATE TABLE IF NOT EXISTS `productionRates` (
  `goodID` int(11) unsigned NOT NULL,
  `productionRate` float unsigned NOT NULL DEFAULT '0',
  KEY `goodsID` (`goodID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `production_rates`
--

INSERT INTO `production_rates` VALUES(1, 0.75);
INSERT INTO `production_rates` VALUES(2, 1.25);
INSERT INTO `production_rates` VALUES(3, 1.25);
INSERT INTO `production_rates` VALUES(4, 0.75);
INSERT INTO `production_rates` VALUES(5, 2.25);
INSERT INTO `production_rates` VALUES(6, 0.75);
INSERT INTO `production_rates` VALUES(7, 1.25);
INSERT INTO `production_rates` VALUES(8, 0.75);
INSERT INTO `production_rates` VALUES(9, 1.5);
INSERT INTO `production_rates` VALUES(10, 1);
INSERT INTO `production_rates` VALUES(11, 0.5);
INSERT INTO `production_rates` VALUES(12, 0.5);
INSERT INTO `production_rates` VALUES(13, 1.25);
INSERT INTO `production_rates` VALUES(14, 0.75);
INSERT INTO `production_rates` VALUES(15, 2);
INSERT INTO `production_rates` VALUES(16, 1);
INSERT INTO `production_rates` VALUES(17, 2.25);
INSERT INTO `production_rates` VALUES(18, 1.25);
INSERT INTO `production_rates` VALUES(19, 1.25);
INSERT INTO `production_rates` VALUES(20, 0.5);


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
