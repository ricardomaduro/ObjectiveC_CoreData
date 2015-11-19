//
//  ChoreLogMO+CoreDataProperties.h
//  CoreDataCoursera
//
//  Created by Ricardo Maduro on 16/11/15.
//  Copyright © 2015 Ricardo Maduro. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "ChoreLogMO.h"

NS_ASSUME_NONNULL_BEGIN

@interface ChoreLogMO (CoreDataProperties)

@property (nullable, nonatomic, retain) NSDate *when;
@property (nullable, nonatomic, retain) CoreMo *chore_done;
@property (nullable, nonatomic, retain) PersonMo *person_who_did_it;

@end

NS_ASSUME_NONNULL_END
