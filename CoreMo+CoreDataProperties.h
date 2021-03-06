//
//  CoreMo+CoreDataProperties.h
//  CoreDataCoursera
//
//  Created by Ricardo Maduro on 16/11/15.
//  Copyright © 2015 Ricardo Maduro. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "CoreMo.h"

NS_ASSUME_NONNULL_BEGIN

@interface CoreMo (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *chore_name;
@property (nullable, nonatomic, retain) NSSet<ChoreLogMO *> *chore_log;

@end

@interface CoreMo (CoreDataGeneratedAccessors)

- (void)addChore_logObject:(ChoreLogMO *)value;
- (void)removeChore_logObject:(ChoreLogMO *)value;
- (void)addChore_log:(NSSet<ChoreLogMO *> *)values;
- (void)removeChore_log:(NSSet<ChoreLogMO *> *)values;

@end

NS_ASSUME_NONNULL_END
