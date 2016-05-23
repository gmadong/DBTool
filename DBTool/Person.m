//
//  Person.m
//  DBTool
//
//  Created by caodong on 16/5/20.
//  Copyright © 2016年 caodong. All rights reserved.
//

#import "Person.h"

@implementation Person

+(instancetype)initName:(NSString *)name age:(int)age
{
    Person *person =[[Person alloc]init];
    person.name = name;
    person.age= age;
    
    return person;
    
}
-(NSString *)description
{
    return [NSString stringWithFormat:@"[name='%@',age='%d']",_name,_age];
}
@end
