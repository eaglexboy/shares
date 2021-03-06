SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `supplies`
--

CREATE TABLE IF NOT EXISTS `supplies` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `ship` int(11) NOT NULL COMMENT 'Ship This supply is for',
  `supplyType` int(100) NOT NULL,
  `amount` float unsigned NOT NULL DEFAULT '0',
  `capacity` smallint(5) unsigned NOT NULL DEFAULT '100',
  PRIMARY KEY (`ID`),
  KEY `supplyType` (`supplyType`),
  KEY `ship` (`ship`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
