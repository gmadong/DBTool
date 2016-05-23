# DBTool
  
  说明:DBTool是对数据库操作的面向对角的封装，使用OC runtime机制实现对sqlite的数据库的增、删、改、查等基本操作省去大量时间编写SQL语句
  
  使用:把DBTool.h、DBTool.m拖入项目中使用即可
  
  
  
    使用
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
    
    //打印
    create sql ->CREATE TABLE IF NOT EXISTS Person(ID INTEGER PRIMARY KEY AUTOINCREMENT,_age TEXT,_name TEXT)
    insert sql ->INSERT INTO Person(_age,_name) VALUES ('19','小明')
    insert sql ->INSERT INTO Person(_age,_name) VALUES ('10','小红')
    insert sql ->INSERT INTO Person(_age,_name) VALUES ('12','小小')
    insert sql ->INSERT INTO Person(_age,_name) VALUES ('23','小黑')
    select sql ->SELECT * FROM Person WHERE  1=1
    [name='小明',age='19']
    [name='小红',age='10']
    [name='小小',age='12']
    [name='小黑',age='23']
    delete sql ->DELETE FROM Person WHERE  _age >= '23' 
    select sql ->SELECT * FROM Person WHERE  1=1
    [name='小明',age='19']
    [name='小红',age='10']
    [name='小小',age='12']
    update sql ->UPDATE Person SET _age = '18' WHERE  _name = '小小' 
    select sql ->SELECT * FROM Person WHERE  1=1
    [name='小明',age='19']
    [name='小红',age='10']
    [name='小小',age='18']
    select sql ->SELECT * FROM Person WHERE  name > '12'
    drop sql ->DROP TABLE 'Person'
