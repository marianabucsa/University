import React from 'react';
import './RoundApp.css'

class RoundRow extends React.Component {
    handleClickDelete = (event) => {
        console.log('delete button pentru ' + this.props.round1.id);
        this.props.deleteFunc(this.props.round1.id);
    };
    handleClickSelect = (event) => {
        document.getElementById('nameTxt').value=this.props.round1.name;
    };

    handleClickUpdate = (event) => {
        console.log('update button pentru ' + this.props.round1.id);
        this.props.round1.name=document.getElementById('nameTxt').value
        this.props.updateFunc(this.props.round1);
    };

    render() {
        return (
            <tr onClick={this.handleClickSelect}>
                <td>{this.props.round1.id}</td>
                <td>{this.props.round1.name}</td>
                <td>
                    <button onClick={this.handleClickDelete}>Delete</button>
                    <button onClick={this.handleClickUpdate}>Update</button>
                </td>
            </tr>
        );
    }
}

class RoundTable extends React.Component {
    render() {
        let rows = [];
        let functieStergere=this.props.deleteFunc;
        let functieUpdate=this.props.updateFunc;
        this.props.rounds.forEach(function(round1) {
            console.log('round'+round1)
            rows.push(<RoundRow round1={round1}  key={round1.id} deleteFunc={functieStergere} updateFunc={functieUpdate} />);
        });
        return (<div className="RoundTable">

                <table className="center">
                    <thead>
                    <tr>
                        <th>Id</th>
                        <th>Name</th>
                        <th>Actions</th>
                    </tr>
                    </thead>
                    <tbody>{rows}</tbody>
                </table>

            </div>
        );
    }
}

export default RoundTable;