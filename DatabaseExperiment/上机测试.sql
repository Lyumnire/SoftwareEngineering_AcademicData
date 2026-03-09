/*
 Navicat Premium Data Transfer

 Source Server         : root
 Source Server Type    : MySQL
 Source Server Version : 80044
 Source Host           : localhost:3306
 Source Schema         : parking_fee

 Target Server Type    : MySQL
 Target Server Version : 80044
 File Encoding         : 65001

 Date: 04/01/2026 16:01:31
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for parking_lots
-- ----------------------------
DROP TABLE IF EXISTS `parking_lots`;
CREATE TABLE `parking_lots`  (
  `pl_id` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '停车场编号',
  `pl_name` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '停车场名称',
  `pl_area` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '所在片区',
  `pl_phone` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL COMMENT '管理电话',
  PRIMARY KEY (`pl_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of parking_lots
-- ----------------------------
INSERT INTO `parking_lots` VALUES ('PL001', 'City Center Parking', 'Central Area', '13800138000');
INSERT INTO `parking_lots` VALUES ('PL002', 'Westside Mall', 'West Area', '13900139000');
INSERT INTO `parking_lots` VALUES ('PL003', 'East Station', 'East Area', NULL);
INSERT INTO `parking_lots` VALUES ('PL004', 'North Park', 'North Area', '13700137000');
INSERT INTO `parking_lots` VALUES ('PL005', 'South Plaza', 'South Area', '13600136000');

-- ----------------------------
-- Table structure for parking_payments
-- ----------------------------
DROP TABLE IF EXISTS `parking_payments`;
CREATE TABLE `parking_payments`  (
  `pp_id` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '扣费记录编号 PP+4位数字',
  `ps_id` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '车位编号',
  `hours` decimal(5, 1) NOT NULL COMMENT '停车时长',
  `pp_date` date NOT NULL COMMENT '扣费日期',
  PRIMARY KEY (`pp_id`) USING BTREE,
  INDEX `fk_payments_spots`(`ps_id`) USING BTREE,
  CONSTRAINT `fk_payments_spots` FOREIGN KEY (`ps_id`) REFERENCES `parking_spots` (`ps_id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of parking_payments
-- ----------------------------
INSERT INTO `parking_payments` VALUES ('PP0001', 'PS001', 2.5, '2025-01-01');
INSERT INTO `parking_payments` VALUES ('PP0002', 'PS001', 3.0, '2025-01-02');
INSERT INTO `parking_payments` VALUES ('PP0003', 'PS002', 1.0, '2025-01-01');
INSERT INTO `parking_payments` VALUES ('PP0004', 'PS003', 5.0, '2025-01-03');
INSERT INTO `parking_payments` VALUES ('PP0005', 'PS005', 10.0, '2025-01-04');
INSERT INTO `parking_payments` VALUES ('PP0006', 'PS006', 0.5, '2025-01-05');

-- ----------------------------
-- Table structure for parking_spots
-- ----------------------------
DROP TABLE IF EXISTS `parking_spots`;
CREATE TABLE `parking_spots`  (
  `ps_id` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '车位编号',
  `pl_id` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '停车场编号',
  `ps_type` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL COMMENT '车位类型',
  `ps_rate` decimal(10, 2) NOT NULL COMMENT '计费单价',
  PRIMARY KEY (`ps_id`) USING BTREE,
  INDEX `fk_spots_lots`(`pl_id`) USING BTREE,
  CONSTRAINT `fk_spots_lots` FOREIGN KEY (`pl_id`) REFERENCES `parking_lots` (`pl_id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of parking_spots
-- ----------------------------
INSERT INTO `parking_spots` VALUES ('PS001', 'PL001', 'Normal', 10.00);
INSERT INTO `parking_spots` VALUES ('PS002', 'PL001', 'EV', 15.00);
INSERT INTO `parking_spots` VALUES ('PS003', 'PL002', 'Normal', 8.00);
INSERT INTO `parking_spots` VALUES ('PS004', 'PL003', 'Disabled', 0.00);
INSERT INTO `parking_spots` VALUES ('PS005', 'PL004', 'Normal', 5.00);
INSERT INTO `parking_spots` VALUES ('PS006', 'PL005', 'EV', 12.00);

-- ----------------------------
-- Procedure structure for sp_get_lot_stats
-- ----------------------------
DROP PROCEDURE IF EXISTS `sp_get_lot_stats`;
delimiter ;;
CREATE PROCEDURE `sp_get_lot_stats`(IN target_pl_id VARCHAR(10))
BEGIN
    SELECT 
        l.pl_name AS '停车场名称',
        COUNT(DISTINCT s.ps_id) AS '已设置车位数量',
        IFNULL(COUNT(p.pp_id), 0) AS '累计停车次数',
        IFNULL(SUM(p.hours), 0) AS '累计停车时长'
    FROM parking_lots l
    LEFT JOIN parking_spots s ON l.pl_id = s.pl_id
    LEFT JOIN parking_payments p ON s.ps_id = p.ps_id
    WHERE l.pl_id = target_pl_id
    GROUP BY l.pl_id;
END
;;
delimiter ;

-- ----------------------------
-- Triggers structure for table parking_payments
-- ----------------------------
DROP TRIGGER IF EXISTS `trg_check_parking_hours`;
delimiter ;;
CREATE TRIGGER `trg_check_parking_hours` BEFORE INSERT ON `parking_payments` FOR EACH ROW BEGIN
    IF NEW.hours <= 0 THEN
        SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'eeor:停车时长必须大于0小时，操作被拒绝！';
    END IF;
END
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;
