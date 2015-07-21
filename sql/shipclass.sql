SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `shipclass`
--

CREATE TABLE IF NOT EXISTS `shipclass` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `shipClass` varchar(25) NOT NULL,
  `shipType` int(10) unsigned NOT NULL DEFAULT '0',
  `cargoRating` int(10) unsigned NOT NULL,
  `maxPassengers` tinyint(4) unsigned NOT NULL,
  `emptyWeight` float unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=11 ;

--
-- Dumping data for table `shipclass`
--

INSERT INTO `shipclass` (`ID`, `shipClass`, `shipType`, `cargoRating`, `maxPassengers`, `emptyWeight`) VALUES
(1, 'Unwin 8 ', 1, 8, 7, 0),
(2, 'Hughes Class', 1, 5, 10, 0),
(3, 'Apollo Class', 2, 10, 0, 0),
(4, 'Damien Class', 2, 8, 0, 0),
(5, 'Olympian Class ', 3, 80, 0, 0),
(6, 'Manchester Class', 3, 100, 0, 0),
(7, 'Titanic Class', 4, 25, 150, 0),
(8, 'White Star Class', 4, 25, 100, 0),
(9, 'Chimera Class', 3, 50, 5, 12),
(10, 'Galaxy Class', 3, 200, 0, 50);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
