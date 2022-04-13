Task:

	After completing the database design, the development team is interested in achieving performance-related results.
	The following relational structure will be created to record multiple test configurations and their run results:
		Tests - contains information about different test configurations.
		Tables - contains lists of tables that could be part of the test.
		TestTables - is the link table between Tests and Tables and contains the list of tables involved in each test.
		Views - a set of views that are used to test the performance of particular queries.
		TestViews - is the link table between Tests and Views and contains the list of views involved in each test.
		TestRuns - contains the results of the execution of various tests.
				Each test run involves the following:
  					-- deleting data from the tables associated with the test (in the order given by the Position field).
  					-- inserting records in tables in the reverse order given by Position (the number of inserted records
					   is given by the NoOfRows field).
  					-- evaluate the execution time of the views.
		TestRunTables - contains performance information for inserting records from each table associated with the test.
		TestRunViews - contains information about the performance of each view in the test.
	
	The implementation of stored procedures for evaluating and storing test results is required. The test must be available 
	for at least three tables and three views:
		-- a table with a field as the primary key and no foreign key
		-- a table with a field as the primary key and at least one foreign key
  		-- a table with two fields as the primary key
		-- a view containing a SELECT command on a table
		-- a view containing a SELECT command applied to at least two tables
		-- a view containing a SELECT command applied to at least two tables and having a GROUP BY clause