SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `markets`
--

CREATE TABLE IF NOT EXISTS `markets` (
  `locationID` int(11) unsigned NOT NULL,
  `goodID` int(11) unsigned NOT NULL,
  `currentValue` float unsigned NOT NULL DEFAULT '0',
  `supply` int(11) unsigned NOT NULL,
  `demand` int(10) unsigned NOT NULL,
  KEY `locationID` (`locationID`,`goodID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `markets`
--
INSERT INTO `markets` VALUES(1, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(1, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(1, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(1, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(1, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(1, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(1, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(1, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(1, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(1, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(1, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(1, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(1, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(1, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(1, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(1, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(1, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(1, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(1, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(1, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(2, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(2, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(2, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(2, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(2, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(2, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(2, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(2, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(2, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(2, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(2, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(2, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(2, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(2, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(2, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(2, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(2, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(2, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(2, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(2, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(4, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(4, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(4, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(4, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(4, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(4, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(4, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(4, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(4, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(4, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(4, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(4, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(4, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(4, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(4, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(4, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(4, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(4, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(4, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(4, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(3, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(3, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(3, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(3, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(3, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(3, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(3, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(3, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(3, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(3, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(3, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(3, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(3, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(3, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(3, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(3, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(3, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(3, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(3, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(3, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(5, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(5, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(5, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(5, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(5, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(5, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(5, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(5, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(5, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(5, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(5, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(5, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(5, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(5, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(5, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(5, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(5, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(5, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(5, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(5, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(6, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(6, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(6, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(6, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(6, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(6, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(6, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(6, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(6, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(6, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(6, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(6, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(6, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(6, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(6, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(6, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(6, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(6, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(6, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(6, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(7, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(7, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(7, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(7, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(7, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(7, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(7, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(7, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(7, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(7, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(7, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(7, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(7, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(7, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(7, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(7, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(7, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(7, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(7, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(7, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(8, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(8, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(8, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(8, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(8, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(8, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(8, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(8, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(8, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(8, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(8, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(8, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(8, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(8, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(8, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(8, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(8, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(8, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(8, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(8, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(9, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(9, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(9, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(9, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(9, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(9, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(9, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(9, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(9, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(9, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(9, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(9, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(9, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(9, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(9, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(9, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(9, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(9, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(9, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(9, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(10, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(10, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(10, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(10, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(10, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(10, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(10, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(10, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(10, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(10, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(10, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(10, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(10, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(10, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(10, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(10, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(10, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(10, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(10, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(10, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(11, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(11, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(11, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(11, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(11, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(11, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(11, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(11, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(11, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(11, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(11, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(11, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(11, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(11, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(11, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(11, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(11, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(11, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(11, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(11, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(12, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(12, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(12, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(12, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(12, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(12, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(12, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(12, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(12, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(12, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(12, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(12, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(12, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(12, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(12, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(12, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(12, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(12, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(12, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(12, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(13, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(13, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(13, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(13, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(13, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(13, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(13, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(13, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(13, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(13, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(13, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(13, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(13, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(13, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(13, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(13, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(13, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(13, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(13, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(13, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(14, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(14, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(14, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(14, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(14, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(14, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(14, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(14, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(14, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(14, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(14, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(14, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(14, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(14, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(14, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(14, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(14, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(14, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(14, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(14, 20, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(15, 1, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(15, 2, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(15, 3, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(15, 4, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(15, 5, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(15, 6, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(15, 7, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(15, 8, 2, 50000000000, 0);
INSERT INTO `markets` VALUES(15, 9, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(15, 10, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(15, 11, 1, 25000000000, 0);
INSERT INTO `markets` VALUES(15, 12, 2, 25000000000, 0);
INSERT INTO `markets` VALUES(15, 13, 0, 100000000000, 0);
INSERT INTO `markets` VALUES(15, 14, 1, 50000000000, 0);
INSERT INTO `markets` VALUES(15, 15, 0, 150000000000, 0);
INSERT INTO `markets` VALUES(15, 16, 0, 75000000000, 0);
INSERT INTO `markets` VALUES(15, 17, 0, 200000000000, 0);
INSERT INTO `markets` VALUES(15, 18, 1, 100000000000, 0);
INSERT INTO `markets` VALUES(15, 19, 2, 100000000000, 0);
INSERT INTO `markets` VALUES(15, 20, 2, 25000000000, 0);


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
