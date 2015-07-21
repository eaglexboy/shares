SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Table structure for table `Users`
--

CREATE TABLE IF NOT EXISTS `Users` (
  `ID` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `firstName` varchar(10) CHARACTER SET ascii NOT NULL COMMENT 'First Name',
  `lastName` varchar(25) CHARACTER SET ascii NOT NULL COMMENT 'Last Name',
  `username` varchar(255) CHARACTER SET ascii NOT NULL COMMENT 'Username',
  `password` char(32) CHARACTER SET ascii NOT NULL COMMENT 'Password MD5',
  `email` varchar(255) CHARACTER SET ascii NOT NULL COMMENT 'User''s Email',
  `bankAccount` float NOT NULL DEFAULT '0' COMMENT 'Player''s Bankroll',
  `stewardEndorsment` tinyint(1) NOT NULL DEFAULT '0',
  `resetHash` char(32) DEFAULT NULL,
  `Enable` tinyint(1) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`),
  KEY `username` (`username`),
  KEY `stewardEndorsment` (`stewardEndorsment`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
