//
//  LGEmailer.h
//  AutoPkgr
//
//  Created by James Barclay on 6/26/14.
//
//  Copyright 2014-2015 The Linde Group, Inc.
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

#import <Foundation/Foundation.h>
#import <MailCore/MailCore.h>

@interface LGEmailer : NSObject

/*
 * complete observable property of current LGEmailer status
 * returns NO while in the process of sending and email, YES on complete or error 
 */
@property (nonatomic, assign) BOOL complete;
@property (copy, nonatomic) void ((^replyBlock)(NSError *));

- (void)sendEmailNotification:(NSString *)subject message:(NSString *)message;
- (void)sendEmailForReport:(NSDictionary *)report error:(NSError *)error;
- (void)sendTestEmail;

@end
