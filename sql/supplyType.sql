SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `supplyType`
--

CREATE TABLE IF NOT EXISTS `supplyType` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `supplyName` varchar(30) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `supplyName` (`supplyName`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `supplyType`
--

INSERT INTO `supplyType` (`ID`, `supplyName`) VALUES
(1, 'water'),
(2, 'food'),
(3, 'oxygen'),
(4, 'volatiles');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;