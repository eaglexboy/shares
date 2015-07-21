SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `goods`
--

CREATE TABLE IF NOT EXISTS `goods` (
  `ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `goodName` varchar(50) CHARACTER SET ascii NOT NULL,
  `goodType` int(11) unsigned NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `goodName` (`goodName`,`goodType`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=21 ;

--
-- Dumping data for table `goods`
--

INSERT INTO `goods` (`ID`, `goodName`, `goodType`) VALUES
(1, 'Technology', 1),
(2, 'Fish', 2),
(3, 'Food', 2),
(4, 'Luxury Food', 2),
(5, 'Water', 2),
(6, 'Cosmetic', 3),
(7, 'Entertainment Products', 3),
(8, 'Finished Goods', 3),
(9, 'Goods', 3),
(10, 'Machine Parts', 3),
(11, 'Pharmaceuticals/Medicine', 3),
(12, 'Security Products', 3),
(13, 'Textiles', 3),
(14, 'Botanic Fuels', 4),
(15, 'Fuel', 4),
(16, 'Processed Materials', 4),
(17, 'Raw Materials', 4),
(18, 'Refined Metals', 4),
(19, 'Entertainment Service', 5),
(20, 'Security Service', 5);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
