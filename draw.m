clear all;
% function draw(x,y)
 a = arduino('/dev/cu.usbmodem14411', 'Uno', 'Libraries', 'MotorAddon/motor', 'forceBuild', true, 'Trace',true); %connects arduino with motor shield library
% a = arduino('/dev/cu.usbmodem14411', 'Uno', 'Libraries', 'MotorAddon/motor');
motor = addon(a,'MotorAddon/motor'); % connects motors
%% possibly move to phase 1????^^^


%% moves stepper motors to correct coordinate
% movemotor(motor,x,y)

% Initializes z axis motor
%moveservo(motor, 200); % moves servo
%pause(5)
%moveservo(motor, 50); %changes servo direction
%moveservo(motor,90); % slows down to servo to stop

