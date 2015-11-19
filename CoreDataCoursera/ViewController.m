//
//  ViewController.m
//  CoreDataCoursera
//
//  Created by Ricardo Maduro on 16/11/15.
//  Copyright © 2015 Ricardo Maduro. All rights reserved.
//

#import "ViewController.h"
#import "AppDelegate.h"

@interface ViewController ()
@property (nonatomic) AppDelegate *appDelegate;
@property (weak, nonatomic) IBOutlet UITextField *choreField;
@property (weak, nonatomic) IBOutlet UILabel *persistedData;
@property (weak, nonatomic) IBOutlet UILabel *itemCount;
@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.appDelegate = [[UIApplication sharedApplication] delegate];
    self.itemCount.text=@"#items=0";
    [self updateLogList];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)deleteChore:(id)sender {
    NSManagedObjectContext *moc = self.appDelegate.managedObjectContext;
    NSFetchRequest *request = [NSFetchRequest fetchRequestWithEntityName:@"Chore"];
    
    NSError *error = nil;
    NSArray *results = [moc executeFetchRequest:request error:&error];
    if (!results){
        NSLog(@"Error fetching person objects: %@\n%@", [error localizedDescription],[error userInfo]);
        abort();
    }
    
    for(CoreMo *c in results){
        [moc deleteObject:c];
    }
    
    [self.appDelegate saveContext];
    
    [self updateLogList];

}

- (IBAction)choreTapped:(id)sender {
    CoreMo *c = [self.appDelegate createCoreMO];
    c.chore_name = self.choreField.text;
    self.choreField.text=@"";
    [self.appDelegate saveContext];
    [self updateLogList];
}

-(void) updateLogList{
    NSManagedObjectContext *moc = self.appDelegate.managedObjectContext;
    NSFetchRequest *request = [NSFetchRequest fetchRequestWithEntityName:@"Chore"];
    
    NSError *error = nil;
    NSArray *results = [moc executeFetchRequest:request error:&error];
    if (!results){
        NSLog(@"Error fetching person objects: %@\n%@", [error localizedDescription],[error userInfo]);
        abort();
    }
    
    NSMutableString *buffer = [NSMutableString stringWithString:@""];
    NSInteger count=0;
    for(CoreMo *c in results){
        [buffer appendFormat:@"\n%@",c.chore_name,nil];
        count++;
    }
    
    self.itemCount.text = [NSString stringWithFormat:@"#items=%d", (int)count];
    
    
    self.persistedData.text = buffer;
}
@end
