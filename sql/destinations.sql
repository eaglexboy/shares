SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `destinations`
--

CREATE TABLE IF NOT EXISTS `destinations` (
  `ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `Name` varchar(30) CHARACTER SET ascii NOT NULL COMMENT 'Destination''s Name',
  `Coordinate` point NOT NULL COMMENT 'Coordinate of Destination',
  `Population` float unsigned NOT NULL COMMENT 'System''s Population',
  `Funds` float unsigned NOT NULL DEFAULT '1000' COMMENT 'System''s Funds',
  `Taxes` float unsigned NOT NULL DEFAULT '5',
  PRIMARY KEY (`ID`),
  KEY `Name` (`Name`,`Export1`,`Export2`,`Export3`,`Export4`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Dumping data for table `destinations`
--

INSERT INTO `destinations` (`ID`, `Name`, `Coordinate`, `Population`, `Funds`, `Taxes`) VALUES
(1, 'Bojam-bura', GeomFromText('POINT(2.75 83.95)')), 0, 1000, 5),
(2, 'Cheektowaga', GeomFromText('POINT(20.28 64.65)')), 0, 1000, 5),
(3, 'Allouette', GeomFromText('POINT(50.06 68.31)')), 0, 1000, 5),
(4, 'Okefenokee', GeomFromText('POINT(58.04 15.06)')), 0, 1000, 5),
(5, 'Byrennios', GeomFromText('POINT(58.29 3.31)')), 0, 1000, 5),
(6, 'Blackrock Belt', GeomFromText('POINT(-4.51 -45.64)')), 0, 1000, 5),
(7, 'Ix', GeomFromText('POINT(-0.33 -75.35)')), 0, 1000, 5),
(8, 'Lafferty', GeomFromText('POINT(-8.49 56.13)')), 0, 1000, 5),
(9, 'Duet', GeomFromText('POINT(-13.85 26.61)')), 0, 1000, 5),
(10, 'Kufiri', GeomFromText('POINT(0 0)')), 0, 1000, 5),
(11, 'Seran', GeomFromText('POINT(28.75 8.57)')), 0, 1000, 5),
(12, 'Franklin', GeomFromText('POINT(24.42 -17.42)')), 0, 1000, 5),
(13, 'Arien', GeomFromText('POINT(33.19 -46.11)')), 0, 1000, 5),
(14, 'Barbary', GeomFromText('POINT(-21.5 -20.92)')), 0, 1000, 5),
(15, 'New Liberty', GeomFromText('POINT(-41.11 -36.55)')), 0, 1000, 5);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
