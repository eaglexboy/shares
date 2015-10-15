
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;


--
-- Table structure for table `importsExports`
--

CREATE TABLE IF NOT EXISTS `imports_exports` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `destination_id` int(11) NOT NULL COMMENT 'System''s ID',
  `goods_id` int(11) NOT NULL COMMENT 'Good ID',
  `export` tinyint(1) NOT NULL COMMENT 'Export or Import',
  PRIMARY KEY (`id`),
  KEY `good_id` (`goods_id`),
  KEY `destination` (`destination_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 COMMENT='System import/Export Links' AUTO_INCREMENT=28 ;

--
-- Dumping data for table `imports_exports`
--

INSERT INTO `imports_exports` (`id`, `destination_id`, `goods_id`, `export`) VALUES
(1, 4, 15, 1),
(2, 4, 8, 0),
(3, 4, 3, 0),
(4, 4, 19, 0),
(5, 4, 7, 0),
(6, 5, 3, 1),
(7, 9, 2, 1),
(8, 9, 13, 1),
(9, 5, 4, 1),
(10, 9, 8, 0),
(11, 9, 15, 0),
(12, 9, 10, 0),
(13, 10, 8, 1),
(14, 10, 17, 0),
(15, 11, 15, 1),
(16, 11, 5, 1),
(17, 11, 8, 0),
(18, 11, 3, 0),
(19, 12, 18, 1),
(20, 12, 3, 0),
(21, 12, 10, 0),
(22, 15, 1, 1),
(23, 15, 3, 1),
(24, 15, 7, 1),
(25, 15, 5, 1),
(26, 15, 17, 0),
(27, 15, 8, 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
