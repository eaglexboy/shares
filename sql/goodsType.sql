SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `goodsType`
--

CREATE TABLE IF NOT EXISTS `goodsType` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `goodType` varchar(25) NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `goodsType` (`goodType`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `goodsType`
--

INSERT INTO `goodsType` (`ID`, `goodType`) VALUES
(1, 'Electronics'),
(2, 'Food'),
(3, 'Goods'),
(4, 'Materials'),
(5, 'Services');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
