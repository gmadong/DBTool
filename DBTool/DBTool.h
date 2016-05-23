//
//  DBTool.h
//
//  Created by caodong on 16/5/20.
//  Copyright © 2016年 caodong. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DBTool : NSObject

/**
 *  得到工具类对象
 *
 *  @return 工具类对象
 */
+ (DBTool *)sharedDBTool;
/**
 *  创建表
 *
 *  @param clazz 实体类class
 */
-(void)createTableWithClass:(Class)clazz;
/**
 *  删除表
 *
 *  @param clazz 实体类class
 */
-(void)dropTableWithClass:(Class)clazz;
/**
 *  删除全部记录
 *
 *  @param clazz 实体类class
 */
-(void)deleteRecordAllWithClass:(Class)clazz;
/**
 *  删除记录(相等)
 *
 *  @param clazz   实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 */
-(void)deleteRecordWithClass:(Class)clazz andKey:(NSString*)keyName isEqualValue:(NSString*)value;
/**
 *  删除记录(大于)
 *
 *  @param clazz   实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 */
-(void)deleteRecordWithClass:(Class)clazz andKey:(NSString*)keyName isGreaterValue:(NSString*)value;
/**
 *  删除记录(大于等于)
 *
 *  @param clazz   实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 */
-(void)deleteRecordWithClass:(Class)clazz andKey:(NSString*)keyName isGreaterEqualValue:(NSString*)value;
/**
 *  删除记录(小于)
 *
 *  @param clazz   实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 */
-(void)deleteRecordWithClass:(Class)clazz andKey:(NSString*)keyName isLessValue:(NSString*)value;
/**
 *  删除记录(小于等于)
 *
 *  @param clazz   实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 */
-(void)deleteRecordWithClass:(Class)clazz andKey:(NSString*)keyName isLessEqualValue:(NSString*)value;
/**
 *  删除记录(like)
 *
 *  @param clazz   实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值(自己加对应%)
 */
-(void)deleteRecordWithClass:(Class)clazz andKey:(NSString*)keyName isLikeValue:(NSString*)value;
/**
 *  删除记录
 *
 *  @param clazz  实体类class
 *  @param params 条件
 */
-(void)deleteRecordWithClass:(Class)clazz  params:(NSString*)params;
/**
 *  查询全部数据
 *  @param clazz 实体类class
 *  @return 查询列表
 */
-(NSMutableArray *)selectAllWithClass:(Class)clazz;
/**
 *  查询数据(大于)
 *
 *  @param clazz   clazz 实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 *
 *  @return 查询列表
 */
-(NSMutableArray *)selectWithClass:(Class)clazz andKey:(NSString*)keyName isGreaterValue:(NSString*)value;
/**
 *  查询数据(大于等于)
 *
 *  @param clazz   clazz 实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 *
 *  @return 查询列表
 */
-(NSMutableArray *)selectWithClass:(Class)clazz andKey:(NSString*)keyName isGreaterEqualValue:(NSString*)value;
/**
 *  查询数据(小于)
 *
 *  @param clazz   clazz 实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 *
 *  @return 查询列表
 */
-(NSMutableArray *)selectWithClass:(Class)clazz andKey:(NSString*)keyName isLessValue:(NSString*)value;
/**
 *  查询数据(小于等于)
 *
 *  @param clazz   clazz 实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值
 *
 *  @return 查询列表
 */
-(NSMutableArray *)selectWithClass:(Class)clazz andKey:(NSString*)keyName isLessEqualValue:(NSString*)value;
/**
 *  查询数据(Like)
 *
 *  @param clazz   clazz 实体类class
 *  @param keyName 实体对象属性名
 *  @param value   对应值(自己加%)
 *
 *  @return 查询列表
 */
-(NSMutableArray *)selectWithClass:(Class)clazz andKey:(NSString*)keyName isLikeValue:(NSString*)value;
/**
 *  查询数据 当params=nil时查询全部
 *
 *  @param clazz 实体类class
 *  @param params  条件
 *  @return 查询列表
 */
-(NSMutableArray *)selectWithClass:(Class)clazz params:(NSString*)params;
/**
 *  插入一条记录
 *
 *  @param obj 实体对象
 */
-(void)insertWithObj:(id)obj;
/**
 *  更新一条记录
 *
 *  @param obj     实体对象
 *  @param keyName 实体对象属性名
 *  @param value   条件值
 *
 */
-(void)updateWithObj:(id)obj andKey:(NSString*)keyName isEqualValue:(NSString*)value;

@end
