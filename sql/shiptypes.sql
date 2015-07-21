SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `shiptypes`
--

CREATE TABLE IF NOT EXISTS `shiptypes` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `shipType` varchar(30) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `shipType` (`shipType`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `shiptypes`
--

INSERT INTO `shiptypes` (`ID`, `shipType`) VALUES
(1, 'Fast Packet'),
(2, 'High Speed Cargo Transport (HS'),
(3, 'Container Freighter'),
(4, 'Passenger Liner');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
