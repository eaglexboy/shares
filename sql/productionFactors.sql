SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `productionFactors`
--

CREATE TABLE IF NOT EXISTS `productionFactors` (
  `goodID` int(11) unsigned NOT NULL,
  `productionFactor` float unsigned NOT NULL DEFAULT '0',
  KEY `goodsID` (`goodID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `production_factors`
--

INSERT INTO `production_factors` VALUES(1, 1.25);
INSERT INTO `production_factors` VALUES(2, 0.25);
INSERT INTO `production_factors` VALUES(3, 0.25);
INSERT INTO `production_factors` VALUES(4, 0.75);
INSERT INTO `production_factors` VALUES(5, 0.2);
INSERT INTO `production_factors` VALUES(6, 0.75);
INSERT INTO `production_factors` VALUES(7, 1.75);
INSERT INTO `production_factors` VALUES(8, 1.5);
INSERT INTO `production_factors` VALUES(9, 1);
INSERT INTO `production_factors` VALUES(10, 0.5);
INSERT INTO `production_factors` VALUES(11, 0.75);
INSERT INTO `production_factors` VALUES(12, 1.8);
INSERT INTO `production_factors` VALUES(13, 0.5);
INSERT INTO `production_factors` VALUES(14, 0.75);
INSERT INTO `production_factors` VALUES(15, 0.5);
INSERT INTO `production_factors` VALUES(16, 0.5);
INSERT INTO `production_factors` VALUES(17, 0.1);
INSERT INTO `production_factors` VALUES(18, 0.75);
INSERT INTO `production_factors` VALUES(19, 2);
INSERT INTO `production_factors` VALUES(20, 2);
INSERT INTO `production_factors` VALUES(1, 1.25);
INSERT INTO `production_factors` VALUES(2, 0.25);
INSERT INTO `production_factors` VALUES(3, 0.25);
INSERT INTO `production_factors` VALUES(4, 0.75);
INSERT INTO `production_factors` VALUES(5, 0.2);
INSERT INTO `production_factors` VALUES(6, 0.75);
INSERT INTO `production_factors` VALUES(7, 1.75);
INSERT INTO `production_factors` VALUES(8, 1.5);
INSERT INTO `production_factors` VALUES(9, 1);
INSERT INTO `production_factors` VALUES(10, 0.5);
INSERT INTO `production_factors` VALUES(11, 0.75);
INSERT INTO `production_factors` VALUES(12, 1.8);
INSERT INTO `production_factors` VALUES(13, 0.5);
INSERT INTO `production_factors` VALUES(14, 0.75);
INSERT INTO `production_factors` VALUES(15, 0.5);
INSERT INTO `production_factors` VALUES(16, 0.5);
INSERT INTO `production_factors` VALUES(17, 0.1);
INSERT INTO `production_factors` VALUES(18, 0.75);
INSERT INTO `production_factors` VALUES(19, 2);
INSERT INTO `production_factors` VALUES(20, 2);


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
