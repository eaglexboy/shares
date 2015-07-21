SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `shipments`
--

CREATE TABLE IF NOT EXISTS `shipments` (
  `ID` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `goodID` int(11) unsigned NOT NULL,
  `sourceID` int(11) unsigned NOT NULL,
  `destinationID` int(11) unsigned NOT NULL,
  `amount` float unsigned NOT NULL DEFAULT '0',
  `payment` float unsigned NOT NULL,
  `dueBy` datetime NOT NULL,
  `priority` tinyint(1) NOT NULL DEFAULT '0',
  `priorityBonus` int(11) unsigned NOT NULL DEFAULT '0',
  `priorityDate` datetime DEFAULT NULL,
  `bulk` tinyint(1) NOT NULL DEFAULT '0',
  `assignedID` int(11) unsigned DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `goodID` (`goodID`,`sourceID`,`destinationID`,`dueBy`,`priority`,`priorityDate`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
