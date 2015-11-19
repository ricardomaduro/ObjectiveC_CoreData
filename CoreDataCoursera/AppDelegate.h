//
//  AppDelegate.h
//  CoreDataCoursera
//
//  Created by Ricardo Maduro on 16/11/15.
//  Copyright © 2015 Ricardo Maduro. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import "CoreMo.h"
#import "PersonMo.h"
#import "ChoreLogMO.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>


@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

-(CoreMo*) createCoreMO;
-(PersonMo*) createPersonMO;
-(ChoreLogMO*) createChoreLogMO;


- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;


@end

