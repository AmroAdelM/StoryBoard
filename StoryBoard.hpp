#include <vector>
#include <string>
#include <list>
#include <algorithm>

namespace Task
{
    class Note
    {
        public:
        std::string title;
    	std::string text;
    	std::list<std::string> tags;
    	
    	bool operator==(const Note& other) const
    	{
    	    return this->title == other.title && this->text == other.text;
    	}
    	
    	bool isAllThoseTagsExist(std::list<std::string> tagsSent)
    	{
    	    bool found = true;
    	    for( auto tag : tagsSent)
    	    {
    	        found &= find(tags.begin(), tags.end(), tag) != tags.end();
    	    }
    	    return found;
    	}
    	
        bool isTagExist(std::string tag)
    	{
    	    return find(tags.begin(), tags.end(), tag) != tags.end();
    	}
    };
     
    class Storyboard
    {
    public:
    	void addNote(Note& note)
    	{
    	    noteList.push_back(note);
    	};
    	void deleteNote(Note& note)
    	{
    	    auto noteFound = std::find(noteList.begin(), noteList.end(), note);
    	    if ( noteFound != noteList.end() )
    	        noteList.erase(noteFound);
    	};
    	
    	Note* searchByTitle(std::string title)
    	{
    	    auto it = find_if(noteList.begin(), noteList.end(), [title] (const Note& s) { return s.title == title; } );
    	    return it==noteList.end()? nullptr : &(*it);
    	};
    	
    	Note* searchByText(std::string text)
    	{
    	    auto it = find_if(noteList.begin(), noteList.end(), [text] (const Note& s) { return s.text == text; } );
    	    return it==noteList.end()? nullptr : &(*it);
    	};
    	
        Note* searchByTag(std::string tag)
    	{
    	    auto it = find_if(noteList.begin(), noteList.end(), [tag] ( Note& s) { return s.isTagExist(tag); } );
    	    return it==noteList.end()? nullptr : &(*it);
    	};
    	
    	Note* searchByTags(std::list<std::string> tags)
    	{
    	    auto it = find_if(noteList.begin(), noteList.end(), [tags] ( Note& s) { return s.isAllThoseTagsExist(tags); } );
    	    return it==noteList.end()? nullptr : &(*it);
    	};
    	
    private:
    	std::vector<Note> noteList;
    };
    
    class TestStoryBoard
    {
        public:
        bool testAddingNote()
        {
            Storyboard obj;
            Note noteForTest;
            noteForTest.title = "Test Traceplayer";
            noteForTest.text = "Implement a unit test for the class Traceplayer of the spark core framework.";
            noteForTest.tags = {"unit test", "traceplayer", "testing", "spark core"};
            obj.addNote(noteForTest);
            auto i = obj.searchByText(noteForTest.text);
            return i != nullptr && i->title == noteForTest.title;
        }
        bool testSearchingByTitle()
        {
            Storyboard obj;
            Note noteForTest;
            noteForTest.title = "Test Traceplayer";
            noteForTest.text = "Implement a unit test for the class Traceplayer of the spark core framework.";
            noteForTest.tags = {"unit test", "traceplayer", "testing", "spark core"};
            obj.addNote(noteForTest);
            auto i = obj.searchByTitle(noteForTest.title);
            return i != nullptr && i->text == noteForTest.text;
        }
        
        bool testSearchingByTag()
        {
            Storyboard obj;
            Note noteForTest;
            noteForTest.title = "Test Traceplayer";
            noteForTest.text = "Implement a unit test for the class Traceplayer of the spark core framework.";
            noteForTest.tags = {"unit test", "traceplayer", "testing", "spark core"};
            obj.addNote(noteForTest);
            auto i = obj.searchByTag("unit test");
            return i != nullptr && i->title == noteForTest.title;
        }
        bool testSearchingBywrongTag()
        {
            Storyboard obj;
            Note noteForTest;
            noteForTest.title = "Test Traceplayer";
            noteForTest.text = "Implement a unit test for the class Traceplayer of the spark core framework.";
            noteForTest.tags = {"unit test", "traceplayer", "testing", "spark core"};
            obj.addNote(noteForTest);
            auto i = obj.searchByTag("unit te");
            return i != nullptr && i->title == noteForTest.title;
        }
        
        bool testDeletingNote()
        {
            Storyboard obj;
            Note noteForTest;
            noteForTest.title = "Test Traceplayer";
            noteForTest.text = "Implement a unit test for the class Traceplayer of the spark core framework.";
            noteForTest.tags = {"unit test", "traceplayer", "testing", "spark core"};
            obj.addNote(noteForTest);
            auto beforeDelete = obj.searchByText(noteForTest.text);
            if( beforeDelete == nullptr || beforeDelete->title != noteForTest.title)
            {
                return false;
            }
            
            obj.deleteNote(*beforeDelete);
            auto afterDelete = obj.searchByText(noteForTest.text);
            return afterDelete == nullptr;
        }
    };
}