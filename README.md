# system_user


USer MAnagement SYstem (USMASY)

The USer MAnagement SYstem (referred to by it’s acronym USMASY (pronounced “us-mass-
sea”) is a simplified multi-user program, designed to be part of a larger programming system.
USMASY plays the vital role of managing user account data, both usernames and passwords.
USMASY will present itself as a menu-based text user interface. The user will be able to enter
several commands to USMASY:

• help - The help command should show a brief list of the available commands to the user.

• load - The load command should prompt the user for a USMASY data file to load into
memory. Each USMASY data file contains a list of users and their private passwords.

• login - The login command allows a user to try to login, they first type their
username, then they get three tries at entering a password. If they can enter a correct
password in that much time the system should print “login successful” otherwise it should
print “login failed”. In a real system, after a successful login the user should be provided a
new user-specific menu. We will not be supporting that behavior in this version of USMASY.

• exit - the exit command exits the program.
