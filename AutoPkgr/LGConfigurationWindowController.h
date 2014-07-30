//
//  LGConfigurationWindowController.h
//  AutoPkgr
//
//  Created by James Barclay on 6/26/14.
//  Copyright (c) 2014 The Linde Group, Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "LGPopularRepositories.h"
#import "LGApplications.h"
#import "LGTestPort.h"

@interface LGConfigurationWindowController : NSWindowController <NSTextDelegate, NSTokenFieldDelegate, NSWindowDelegate>
{
    NSUserDefaults *defaults;
}

// Text/token fields
@property (weak) IBOutlet NSTokenField *smtpTo;
@property (weak) IBOutlet NSTextField *smtpFrom;
@property (weak) IBOutlet NSTextField *smtpServer;
@property (weak) IBOutlet NSTextField *smtpUsername;
@property (weak) IBOutlet NSSecureTextField *smtpPassword;
@property (weak) IBOutlet NSTextField *smtpPort;
@property (weak) IBOutlet NSTextField *repoURLToAdd;
@property (weak) IBOutlet NSTextField *autoPkgRunInterval;
@property (weak) IBOutlet NSTextField *localMunkiRepo;

// Checkboxes
@property (weak) IBOutlet NSButton *smtpAuthenticationEnabledButton;
@property (weak) IBOutlet NSButton *smtpTLSEnabledButton;
@property (weak) IBOutlet NSButton *warnBeforeQuittingButton;
@property (weak) IBOutlet NSButton *checkForNewVersionsOfAppsAutomaticallyButton;
@property (weak) IBOutlet NSButton *checkForRepoUpdatesAutomaticallyButton;
@property (weak) IBOutlet NSButton *sendEmailNotificationsWhenNewVersionsAreFoundButton;

// Buttons
@property (weak) IBOutlet NSButton *autoPkgCacheFolderButton;
@property (weak) IBOutlet NSButton *autoPkgRecipeReposFolderButton;
@property (weak) IBOutlet NSButton *localMunkiRepoFolderButton;
@property (weak) IBOutlet NSButton *sendTestEmailButton;
@property (weak) IBOutlet NSButton *installGitButton;
@property (weak) IBOutlet NSButton *installAutoPkgButton;
@property (weak) IBOutlet NSButton *checkAppsNowButton;
@property (weak) IBOutlet NSButton *updateRepoNowButton;

// Labels
@property (weak) IBOutlet NSTextField *gitStatusLabel;
@property (weak) IBOutlet NSTextField *autoPkgStatusLabel;

// Status icons
@property (weak) IBOutlet NSImageView *gitStatusIcon;
@property (weak) IBOutlet NSImageView *autoPkgStatusIcon;
@property (weak) IBOutlet NSImageView *sendTestEmailStatus;
@property (weak) IBOutlet NSImageView *testSmtpServerStatus;

// Spinners
@property (weak) IBOutlet NSProgressIndicator *sendTestEmailSpinner;
@property (weak) IBOutlet NSProgressIndicator *testSmtpServerSpinner;
@property (weak) IBOutlet NSProgressIndicator *checkAppsNowSpinner;
@property (weak) IBOutlet NSProgressIndicator *updateRepoNowSpinner;

// Objects
@property (strong) IBOutlet LGPopularRepositories *popRepoTableViewHandler;
@property (strong) IBOutlet LGApplications *appTableViewHandler;

// IBActions
- (IBAction)sendTestEmail:(id)sender;
- (IBAction)installGit:(id)sender;
- (IBAction)installAutoPkg:(id)sender;
- (IBAction)openAutoPkgCacheFolder:(id)sender;
- (IBAction)openAutoPkgRecipeReposFolder:(id)sender;
- (IBAction)openLocalMunkiRepoFolder:(id)sender;
- (IBAction)addAutoPkgRepoURL:(id)sender;
- (IBAction)updateReposNow:(id)sender;
- (IBAction)checkAppsNow:(id)sender;
- (IBAction)chooseLocalMunkiRepo:(id)sender;

- (void)runCommandAsRoot:(NSString *)command;
- (void)downloadAndInstallAutoPkg;

@end
