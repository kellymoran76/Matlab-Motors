classdef motor < arduinoio.LibraryBase
    properties(Access = private,Constant = true)
        RUN_Y = hex2dec('01');
        RUN_X = hex2dec('02');
        SERVO_COMMAND = hex2dec('03');
        
    end
    properties(Access = protected,Constant = true)
        LibraryName = 'MotorAddon/motor';
        DependentLibraries = {};
        ArduinoLibraryHeaderFiles = {'AccelStepper-master/AccelStepper.h','Adafruit-Motor-Shield-library-master/AFMotor.h','Servo/Servo.h'};
        CppHeaderFile = fullfile(arduinoio.FilePath(mfilename('fullpath')),'src','motor.h');
        CppClassName = 'motor';
    end
    properties(Access = private)
        ResourceOwner = 'motor';
    end
    methods
        function obj = motor(parentObj)
            disp('making object')
            obj.Parent = parentObj;
            obj.Pins = [];
        end
        function runY(obj,yposition)
            cmdID = obj.RUN_Y;
            inputs = [yposition];
            response = sendCommand(obj,obj.LibraryName,cmdID,inputs);
        end
        function runX(obj,xposition)
            cmdID = obj.RUN_X;
            inputs = [xposition];
            response = sendCommand(obj,obj.LibraryName,cmdID,inputs);
            
        end
        function moveservo(obj,position)
            cmdID = obj.SERVO_COMMAND;
            inputs = [position];
            response = sendCommand(obj,obj.LibraryName,cmdID,inputs);
            disp('moved servo')
        end
    end
end