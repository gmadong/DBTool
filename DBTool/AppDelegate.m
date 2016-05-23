//
//  AppDelegate.m
//  DBTool
//
//  Created by caodong on 16/5/20.
//  Copyright © 2016年 caodong. All rights reserved.
//

#import "AppDelegate.h"
#import "Person.h"
#import "DBTool.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    DBTool *tool = [DBTool sharedDBTool];
    [tool createTableWithClass:[Person class]];
    Person *p = [Person initName:@"小明" age:19];
    [tool insertWithObj:p];
    Person *p1 = [Person initName:@"小红" age:10];
    [tool insertWithObj:p1];
    Person *p2 = [Person initName:@"小小" age:12];
    [tool insertWithObj:p2];
    Person *p3 = [Person initName:@"小黑" age:23];
    [tool insertWithObj:p3];
    
    NSArray *data = [tool selectWithClass:[Person class] params:nil];
    for (int i=0;i<data.count;i++)
    {
        Person *p4 = data[i];
        NSLog(@"%@",p4);
    }
    [tool deleteRecordWithClass:[Person class] andKey:@"age" isGreaterEqualValue:@"23"];
    data = [tool selectWithClass:[Person class] params:nil];
    for (int i=0;i<data.count;i++)
    {
        Person *p3 = data[i];
        NSLog(@"%@",p3);
    }
    p2.age = 18;
    [tool updateWithObj:p2 andKey:@"name" isEqualValue:@"小小"];
    data = [tool selectAllWithClass:[Person class]];
    for (int i=0;i<data.count;i++)
    {
        Person *p3 = data[i];
        NSLog(@"%@",p3);
    }
    data = [tool selectWithClass:[Person class] andKey:@"name" isGreaterValue:@12];
    for (int i=0;i<data.count;i++)
    {
        Person *p3 = data[i];
        NSLog(@"%@",p3);
    }
    [tool dropTableWithClass:[Person class]];
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
