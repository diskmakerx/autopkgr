// LGNotificationServiceWindowController.m
// 
// Copyright 2015 The Linde Group, Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//


#import "LGNotificationServiceWindowController.h"
#import "LGBaseNotificationServiceViewController.h"
#import "LGNotificationService.h"


@interface LGNotificationServiceWindowController ()
@property (strong, nonatomic, readonly) LGBaseNotificationServiceViewController<LGNotificationServiceProtocol> *viewController;
@end

@implementation LGNotificationServiceWindowController
- (instancetype)initWithViewController:(LGBaseNotificationServiceViewController *)viewController {
    return [super initWithViewController:(NSViewController *)viewController];
}

- (void)awakeFromNib {
    self.configBox.title = [[self.viewController.service class] serviceDescription] ?: @"";

    self.accessoryButton.hidden = NO;
    self.accessoryButton.title = NSLocalizedString(@"Send Test", @"Test notification button title.");
    self.accessoryButton.action = @selector(sendNotificationTest:);
    self.accessoryButton.target = self;
}

- (void)sendNotificationTest:(id)sender {
    [self.progressSpinner startAnimation:self];
    self.infoTextField.stringValue = @"";
    self.accessoryButton.enabled = NO;

    [self.viewController.service sendTest:^(NSError *error) {
        if (error) {
            [NSApp presentError:error];
        } else {
            self.infoTextField.stringValue = NSLocalizedString(@"Successfully sent test notification ", nil);
        }

        self.accessoryButton.enabled = YES;
        [self.progressSpinner stopAnimation:self];
    }];
}
@end
