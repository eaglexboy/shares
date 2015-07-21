SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `consumptionRates`
--

CREATE TABLE IF NOT EXISTS `consumptionRates` (
  `goodID` int(11) unsigned NOT NULL,
  `consumptionRate` float unsigned NOT NULL DEFAULT '0',
  KEY `goodID` (`goodID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `destinations`
--
INSERT INTO `consumption_rates` (`goodID`, `consumptionRate`) VALUES
(1, 0.5),
(2, 1),
(3, 1),
(4, 0.5),
(5, 2),
(6, 0.5),
(7, 1),
(8, 0.5),
(9, 1),
(10, 0.75),
(11, 0.25),
(12, 0.25),
(13, 1),
(14, 0.5),
(15, 1.5),
(16, 0.75),
(17, 2),
(18, 1),
(19, 1),
(20, 0.25);


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
