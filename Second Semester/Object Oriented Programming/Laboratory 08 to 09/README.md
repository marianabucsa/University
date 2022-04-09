Task:
	
	Modify the application from the previous laboratory:
		-- use Vector class from STL, replace all the for loops with STL algorithms.
 		-- use exceptions to report errors (create your own exception classes).
		
		Pharmacy
			-- add the ability to create a prescription. The user can create an interactive list of prescripted drugs.
			-- empty prescription: delete all prescripted drugs.
			-- add to prescription: add a medicine by name.
			-- generate prescription: the user enters the total number of drugs, the prescription is randomly populated with drugs.
			-- export/save prescription to file: CVS or HTML. The file is saved only when this menu is selected, the basket is not
			   persistent (on application restart the basket is empty again), the user enters the file name where the prescription is
			   saved on each export.
  			-- after each user action, the total number of drugs on the prescription is displayed.
			-- add the possibility to save the medicine in a file.
			-- undo for the following features: add, delete, modify. Use inheritance and polymorphism.