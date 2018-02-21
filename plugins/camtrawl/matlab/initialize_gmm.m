function GMM_detector = initialize_gmm(num_frames,init_var)

GMM_detector = vision.ForegroundDetector(...
       'NumTrainingFrames', num_frames, ...
       'InitialVariance', init_var);
